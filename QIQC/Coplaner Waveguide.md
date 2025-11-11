# Coplaner Waveguide

Coplanar waveguide (CPW) is a type of planar transmission line technology. It consists of one central conductor track (signal strip) and two parallel return conductors that are located on the same plane. All three conductors are printed on a single dielectric substrate. In one of its common variants, the "conductor-backed coplanar waveguide (CBCPW)", a complete ground plane is added to the back of the substrate, which serves as the third return conductor.

<img src="D:\Notes\QIQC\fig\CPW layout.png" style="zoom:70%;" />

## 1 Effective dielectric and characteristic impendence

For a conventional CPW, the magior design parameters are

<img src="D:\Notes\QIQC\fig\layout2.png" style="zoom:45%;" />

Denote 
$$
\begin{align}
k_0&=\frac{S}{S+2W}\\
k_0'&=\sqrt{1-{k_0}^2}
\end{align}
$$
and
$$
\begin{align}
k_1&=\frac{\sinh(\pi S/4h)}{\sinh(\pi (S+2W)/4h)}\\
k_1'&=\sqrt{1-{k_1}^2}
\end{align}
$$
The formula for effective dielectric is
$$
\varepsilon_{\text{eff}}=1+\frac{\varepsilon_r-1}{2}\frac{K(k_1)}{K(k_1')}\frac{K(k_0')}{K(k_0)}
$$
where $K(x)$ stands for the first kind elliptic integral. The formula for characteristic impendence is
$$
Z_0=\frac{30\pi}{\sqrt{\varepsilon_{\text{eff}}}}\frac{K(k_0')}{K(k_0)}
$$
The formulas of other CPW forms can be found in[《Coplanar Waveguide Circuits, Components, and Systems》](https://onlinelibrary.wiley.com/doi/book/10.1002/0471224758)

>   [!note]
>
>   For example, we now consider depositing a superconducting metal layer with a thickness of $100\mathrm{n m}$ on an intrinsic silicon substrate that is $500\mathrm{\mu m}$ thick, where the width of the central conductor is $10\mathrm{\mu m}$ and the gaps on both sides are $6\mathrm{\mu m}$ each
>
>   | $S$                | $W$               | $h$                 | $\varepsilon_r$ |
>   | ------------------ | ----------------- | ------------------- | --------------- |
>   | $10\mathrm{\mu m}$ | $6\mathrm{\mu m}$ | $500\mathrm{\mu m}$ | $11.9$          |
>
>   take the parameters into the formulas, we obtained
>
>   | $\varepsilon_{\text{eff}}$ | $Z_0$        |
>   | -------------------------- | ------------ |
>   | $6.45$                     | $51.8\Omega$ |
