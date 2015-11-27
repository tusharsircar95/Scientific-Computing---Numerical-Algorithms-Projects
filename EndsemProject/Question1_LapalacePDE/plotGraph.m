data1 = load("output_beta3_1.txt");
data2 = load("output_beta3_2.txt");
data3 = load("output_beta3_3.txt");
data = load("analyticOutput_beta3_3.txt");

plot(data(:,1),data(:,2),data1(:,1),data1(:,2),data2(:,1),data2(:,2),data3(:,1),data3(:,2));
ylabel('Temperature');
xlabel('Time');
title('Beta = 2.0');
set(gca,'XTick',0:0.2:2)
legend("Analytic Solution","deltaT = 0.1","deltaT = 0.05","deltaT = 0.025");
