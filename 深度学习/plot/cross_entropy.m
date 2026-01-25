clear; clc;

function [loss_mse, loss_ce] = loss(w1, w2) 
    y_1 = 1 ./ (1 + exp(-abs(w1)));
    y_hat = 1 ./ (1 + exp(-abs(w2) .* y_1));
    y_true = 0.5;
    loss_mse = (y_true - y_hat).^2;
    loss_ce = -(y_true .* log(y_hat + eps) + (1 - y_true) .* log(1 - y_hat + eps));
end


[w1, w2] = meshgrid(-10:0.2:10, -10:0.2:10);

[loss_mse, loss_ce] = loss(w1, w2);

x0 = -8;
y0 = 7;

[loss_m, loss_c] = loss(x0, y0);

figure('Position', [100, 100, 800, 500]);


mesh(w1, w2, loss_mse);
hold on;
mesh(w1, w2, loss_ce);
hold on;

scatter3(x0,y0,loss_m,60,"k","filled");
scatter3(x0,y0,loss_c,60,"k","filled");

text(x0, y0-0.5, loss_m+0.6, sprintf('MSE'), 'VerticalAlignment', 'top', 'HorizontalAlignment', 'right', 'FontSize', 12,'FontWeight','bold');
text(x0, y0-0.5, loss_c+0.5, sprintf('CE'), 'VerticalAlignment', 'top', 'HorizontalAlignment', 'right', 'FontSize', 12,'FontWeight','bold');

title('MSE vs Cross-Entropy Loss Surfaces','FontSize',16);
xlabel('w_1','FontSize',12); ylabel('w_2','FontSize',12); zlabel('Loss','FontSize',12);
colorbar;
shading interp;
