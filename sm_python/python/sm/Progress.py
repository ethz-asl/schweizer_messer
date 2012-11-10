import time
import datetime
class Progress(object):
    def __init__(self, numIterations):
        self.started = False
        self.elapsed = 0
        self.startTime = 0
        self.numIterations = numIterations
        self.iteration = 0

    def sample(self):
        if self.started:
            self.iteration = self.iteration + 1
            self.elapsed = time.time() - self.startTime
            timePerRun = self.elapsed / self.iteration
            totalTime = self.numIterations * timePerRun
        
            print "Progress %d / %d" % (self.iteration, self.numIterations)
            print "Time %s / %s  (%s * %d) " % (datetime.timedelta(seconds=self.elapsed), datetime.timedelta(seconds=totalTime), datetime.timedelta(seconds=timePerRun), self.numIterations)

        else:
            self.startTime = time.time()
            self.iteration = 0
            self.started = True
