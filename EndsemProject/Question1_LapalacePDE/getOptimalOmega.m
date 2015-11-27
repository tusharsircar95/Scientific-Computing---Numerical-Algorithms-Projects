function getOptimalOmega(x,y)
beta = x/y;
e = (cos(pi/x) + (beta*beta*cos(pi/y)))/(1 + (beta*beta));
e = e*e;
w = 2 * (1 - sqrt(1-e))/(e);
w
end