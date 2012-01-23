function [ r, drho_dm ] = epoly( pol, M )
%EPOLY Summary of this function goes here
%   Detailed explanation goes here


M2 = M .* M;
n = sqrt(M2(1,:) + M2(2,:));
u = M(3)/n;
x = M(1);
y = M(2);
z = M(3);
w = M(4);
theta = atan(u);
p = M(1:3,1)'*M(1:3,1);

rho = pol(1);
t_i = 1;
drho_dtheta = 0.0;
for i = 2:length(pol)
    drho_dtheta = drho_dtheta + (i-1) * t_i * pol(i);
    t_i = t_i * theta;
    rho = rho + pol(i) * t_i;
end

r = rho/n;
drho_dtheta * (-x*z)/(n*n*p)
drho_dtheta * (1/(1+u*u))*((-x*z)/(n*n*n))/n

drho_dm = [drho_dtheta * (1/(1+u*u))*((-x*z)/(n*n*n)) / n - rho*x/(n*n*n), 0, 0, 0];
drho_dm = [(drho_dtheta * (-x*z))/(n*n*p) - rho*x/(n*n*n), 0, 0, 0];
end

