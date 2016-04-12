import os
import yaml
import math

import roslib

import sm

import numpy as np
import numpy.linalg
import scipy.stats as stat
import scipy

def angularQuatDist(q1, q2):
    return 2 * np.arccos(min(1, np.abs(np.dot(q1, q2))));

def angularQuatDists(q, quats):
    return np.array([ angularQuatDist(q, q2) for q2 in quats ]);

def exp(q, a):
    return sm.quatPlus(q).dot(sm.axisAngle2quat(a));

def totalSquaredDist(q, quats):
    return sum(angularQuatDists(q, quats)**2)

def quatMean(q0, quats):
    res = scipy.optimize.minimize(lambda a : totalSquaredDist(exp(q0, a), quats), np.zeros(3))
    #print res
    return exp(q0, res.x)

def quatVar(qMean, quats):
    return totalSquaredDist(qMean, quats) / len(quats)

n = 100;
sigma = 0.2
randVector = np.random.multivariate_normal(np.zeros(3), np.identity(3) * sigma * sigma, n)

qStart = sm.quatRandom()
quats = [ exp(qStart, randVector[i, :]) for i in range(n) ]

#print quats;
#print angularQuatDists(sm.quatIdentity(), quats)
print np.linalg.norm(angularQuatDists(qStart, quats) - np.linalg.norm(randVector, 2, 1), 2), '~', 0 

q0 = qStart

qMean = quatMean(q0, quats)
print "qMean=", qMean, '~', qStart

qVar = quatVar(qMean, quats)
print "qVar=", qVar, '~', np.mean(np.linalg.norm(randVector, 2, 1)**2), '~', 3 * sigma * sigma

a = np.array([[0, 1, 0], [0, -1, 0], [1, 0, 0], [-1, 0, 0], [0, 0, 1], [0, 0, -1]])

print np.linalg.norm(quatMean(sm.quatIdentity(), np.array([ exp(qStart, a[i]) for i in range(len(a))])) + qStart) 
