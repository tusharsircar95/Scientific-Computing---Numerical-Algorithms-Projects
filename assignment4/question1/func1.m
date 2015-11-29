function v = func1(x)

v = (ones(size(x))*25) - (x.^2);
v = sqrt(v);

plot(x,v,"color","r");
plot(x,-v,"color","r");


end