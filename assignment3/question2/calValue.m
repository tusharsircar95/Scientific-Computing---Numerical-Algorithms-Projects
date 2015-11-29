function v = calValue(x)

v1 = (3*x) + ones(size(x));
v1 = (3*ones(size(v1))) .^ (v1);

v2 = 2*x;
v2 = (7.5*ones(size(v2))) .^ v2;

v = v1 + v2;

end