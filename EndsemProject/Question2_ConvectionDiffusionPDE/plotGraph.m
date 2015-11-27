data1 = load("output_Re3_1.txt");
data2 = load("output_Re3_2.txt");
data3 = load("output_Re3_3.txt");
data = load("aOutput.txt");

plot(data(:,1),data(:,2),data1(:,1),data1(:,2),data2(:,1),data2(:,2),data3(:,1),data3(:,2));
ylabel('u');
xlabel('x');
title('Re = 100');
set(gca,'XTick',0:0.2:1)
legend("Analytic Solution","deltaX = 0.1","deltaX = 0.05","deltaX = 0.025");
