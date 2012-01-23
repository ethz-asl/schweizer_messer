oc = getCam('B')
p = rand(4,1);
p(1:2) = p(1:2) - 0.5;
p(3) = 1*(p(3)-0.95);

p = [1e-6;0;-10;1];

estY = jacobianest(@(X)w2c(X, oc,true), p);
[y,Y] = w2c(p,oc);

Y
estY

%%

pol = fliplr(oc.pol);
M = [0;0;-10;1]
f = @(X) epoly(pol, X);
estY = jacobianest(f, M);
[y,Y] = epoly(pol,M);

Y
estY