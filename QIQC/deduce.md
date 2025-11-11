# deduce

<img src="fig\image%202.png" alt="image.png" style="zoom:40%;" />

We note the potential at the node as $V_n$, the magnetic flux is hence

$$
\Phi=\int_{-\infty}^{t}V_n(\tau)\mathrm{d}\tau
$$

and $\displaystyle \dot{\Phi}=V_n(t)$. Thus the energy of the transmon is

$$
E_t=\frac{1}{2}C\dot{\Phi}^2+\frac{1}{2L}\Phi^2
$$

The energy in $C_d$

$$
\begin{align*}E_d&=\frac{1}{2}C_d\left(V_d-V_n\right)^2\\
&=\frac{1}{2}C_dV_d^2-C_dV_dV_n+\frac{1}{2}C_dV_n^2
\end{align*}
$$

The Lagrangian of the system is 

$$
L=\frac{1}{2}(C+C_d)\dot{\Phi}^2-C_dV_d\dot{\Phi}+\frac{1}{2L}\Phi^2+\underbrace{\frac{1}{2}C_dV_d^2}_{\text{drop}}
$$

Then we can obtain the generalized momentum

$$
\tilde{Q}=\frac{\partial L}{\partial\dot{\Phi}}=C_{\scriptscriptstyle{\sum}}\dot{\Phi}-C_dV_d
$$

The Hamiltonian is so that

$$
\begin{align*}H&=\tilde{Q}\dot{\Phi}-L\\&=\underbrace{\frac{\tilde{Q}^2}{2C_{\scriptscriptstyle{\sum}}}+\frac{\Phi^2}{2L}}_{LC}+\underbrace{\frac{C_\text{d}}{C_{\scriptscriptstyle{\sum}}}V_\text{d}\tilde{Q}}_{\text{coupling}}\end{align*}
$$