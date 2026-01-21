% 定义函数
local_minimum = @(x,y) 0.2*(x.^2 + y.^2);
local_maximum = @(x,y) -0.2*(x.^2 + y.^2);
saddle_point = @(x,y) 0.2*(x.^2 - y.^2);

funcs = {local_minimum, local_maximum, saddle_point};
titles = {'Local Minimum', 'Local Maximum', 'Saddle Point'};

% 生成网格
x_range = [-2, 2];
y_range = [-2, 2];
x = linspace(x_range(1), x_range(2), 100);
y = linspace(y_range(1), y_range(2), 100);
[X, Y] = meshgrid(x, y);

% 作图
% figure('Position',[100 100 1500 400]);
% for i = 1:length(funcs)
%     Z = funcs{i}(X, Y);
%     subplot(1, length(funcs), i)
%     mesh(X, Y, Z)
%     hold on
%     scatter3(0,0,funcs{i}(0,0),60,"black","filled")
%     shading interp
%     colormap parula
%     title(titles{i})
%     xlabel('X axis')
%     ylabel('Y axis')
%     zlabel('Z axis')
% end

figure('Position',[100 100 1000 400]);
Z1 = 0.2 * x.^2;
Z2 = saddle_point(X,Y);

subplot(1,2,1);
plot(x,Z1,'LineWidth',1,'Color','r');
title("One-dimensional")
hold on
scatter(0,0,60,'black','filled')

subplot(1,2,2);
mesh(X,Y,Z2);
shading interp
colormap parula
title("Two-dimensional")
hold on
scatter3(0,0,saddle_point(0,0),60,"black","filled")
