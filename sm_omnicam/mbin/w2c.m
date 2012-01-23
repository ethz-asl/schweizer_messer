function [ yy, Y ] = w2c(M, ocam_model,force)

if nargin < 3
    force = false;
end

xc = ocam_model.xc;
yc = ocam_model.yc;
c = ocam_model.c;
d = ocam_model.d;
e = ocam_model.e;
pol = fliplr(ocam_model.pol);

K = [c d xc;
     e 1 yc;
     0 0 1];
M2 = M .* M;
n = sqrt(M2(1,:) + M2(2,:));

theta = atan2(M(3,:),n);


rho = pol(1);
t_i = 1;
drho_dtheta = 0.0;
for i = 2:length(pol)
    drho_dtheta = drho_dtheta + (i-1) * t_i * pol(i);
    t_i = t_i * theta;
    rho = rho + pol(i) * t_i;
end

x = M(1);
y = M(2);
z = M(3);
w = M(4);

small = 1e-5;
n2 = n*n;
n3 = n*n2;


if n < small && ~force
    yy = [xc;yc];
    Y = zeros(2,4);
    
    Y(1,1) = -(c/z) * drho_dtheta;
    Y(1,2) = -(d/z) * drho_dtheta;
    Y(2,1) = -(e/z) * drho_dtheta;
    Y(2,2) = -(1/z) * drho_dtheta;
else
    
    if n < eps
        n = eps; 
    end

b = (w*rho)/n;
D = [  b,  0,  0, 0;
       0,  b,  0, 0;
       0   0,  0, 1];

yh = K*D*M;
yy = fromHomogeneous(yh);


% Now the Jacobian calculation.
p = sum(M2(1:3,:));

db_dx = -w * ((drho_dtheta * x * z)/(n2*p) + rho*x/(n3));%( ((x*z*drho_dtheta)/(n*n*p)) + ((rho * x)/n*n*n));
db_dy = -w * ((y*z*drho_dtheta)/(n2*p) + (rho * y)/(n3));
db_dz = (w*drho_dtheta)/(p);
db_dw = rho/n;

Yi = [ db_dx * x + b, db_dy * x    , db_dz * x, db_dw * x;
      db_dx * y    , db_dy * y + b, db_dz * y, db_dw * y;
        0          ,      0       ,    0     ,  1];
% The jacobian of the "from homogeneous" function
H = (1/yh(3))*[eye(2), -yy];

Y = H * K * Yi;
end

fprintf('Result:    [%5.2f, %5.2f]\n', yy(1,:), yy(2,:));
m = world2cam_fast(fromHomogeneous(M), ocam_model);
fprintf('Benchmark: [%5.2f, %5.2f]\n', m(1,:), m(2,:));

end


