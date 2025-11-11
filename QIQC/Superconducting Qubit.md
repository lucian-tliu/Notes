# 1. LC Oscillator

The classical Lagrangian of a LC oscillator is

$$
L=\frac{1}{2}LI^2-\frac{Q^2}{2C}
$$

Take $I=\dot{Q}$ into the expression, we obtain

$$
L=\frac{1}{2}L\dot{Q}^2-\frac{Q^2}{2C}
$$

Deem Q as the generalized location, the corresponding momentum is

$$
\Phi=\frac{\partial L}{\partial\dot{Q}}=L\dot{Q}
$$

which is the magnetic flux of the system. Hence the Hamiltonian is

$$
H=\frac{\Phi^2}{2L}+\frac{Q^2}{2C}
$$

Utilize the canonical equation

$$
\dot{\Phi}=-\frac{\partial H}{\partial Q}=-\frac{Q}{C}
$$

Therefore

$$
H=\frac{1}{2}C\dot{\Phi}^2+\frac{1}{2L}\Phi^2
$$

which represents a oscillator. We can solve it by defining the annihilation operator $\hat{a}$ and create operator $\hat{a}^\dagger$

$$
\begin{align*}\hat{a}&=\sqrt{\frac{1}{2\hbar Z}}\hat{\Phi}+i\sqrt{\frac{Z}{2\hbar}}\hat{Q}\\\hat{a}^\dagger&=\sqrt{\frac{1}{2\hbar Z}}\hat{\Phi}-i\sqrt{\frac{Z}{2\hbar}}\hat{Q}\end{align*}
$$

where $Z=\sqrt{L/C}$ is the characteristic impedance. Then the Hamiltonian can be written as

$$
\hat{H}=\hbar\omega\left(\hat{a}^\dagger\hat{a}+\frac{1}{2}\right)
$$

corresponds to equidistant energy level.

# 2. Josephson junction and transmon qubit

In order to control the qubit with microwave we have to  introduce an nonlinear component into the system. Josephson junction is the only known component that simultaneously satisfies both nonlinearity and low loss.

<img src="fig\image.png" alt="image.png" style="zoom:33%;" />

A Josephson junction is composed of superconductors on both sides and an insulator in the middle. The state of Josephson junction is noted as $|m\rangle$ which represents the number of Cooper pairs tunneling from left to right. In detail

$$
|m\rangle=|N_L-m,N_R+m\rangle
$$

The Hamiltonian is

$$
H=-E_J\sum_{m}\left(|m\rangle\langle m+1|+|m+1\rangle\langle m|\right)
$$

where $E_J$ is the Josephson energy. The Hamiltonian is similar to that of a one-dimensional lattice model. The basic wave function is like a plane wave

$$
|\varphi\rangle=\sum_{m=-\infty}^{+\infty}\mathrm{e}^{\mathrm{i} m\varphi}|m\rangle
$$

Hence the eigenvalue of the Hamiltonian (the eigen energy) is

$$
H|\varphi\rangle=-E_J\cos\varphi|\varphi\rangle
$$

To construct a transmon qubit, we connect a capacitor to the Josephson junction

<img src="fig\image%201.png" alt="image.png" style="zoom:30%;" />

As $\displaystyle \hat{n}=\frac{\hat{Q}}{2e}$ and $\displaystyle \hat\varphi= 2\pi\frac{\Phi}{\Phi_0}$, where $\Phi_0=h/2e$

The total energy is 

$$
\begin{align*}E&=\frac{(2en)^2}{2C}-E_J\cos\varphi\\&=4E_C\hat{n}^2-E_J\cos\hat{\varphi}\end{align*}
$$

where $\displaystyle E_C=\frac{e^2}{2C}$. Over time, the superconducting qubit community has converged toward circuit designs with $E_J\gg E_C$ . In the opposite case when , the qubit becomes highly sensitive to charge noise, which has proven more challenging to mitigate than flux noise, making it very hard to achieve high coherence. We can achieve that by shunting the junction with a large capacitor.

Generally, we consider the states near the ground state (selected as the computational bits), where $\varphi$ is small. However, it should be noted that higher physical energy levels still exist. Then the Hamiltonian can be expanded to

$$
\hat{H}=\underbrace{4E_C\hat{n}^2+\frac{1}{2}E_J\hat{\varphi}^2}_{\text{QHO}}-\underbrace{\frac{1}{24}E_J\hat{\varphi}^4}_{\text{nonlinear item}}
$$

We can define the corresponding annihilation $\hat{b}$ and create $\hat{b}^\dagger$ operator

$$
\begin{align*}\hat{b}&=\left(\frac{E_J}{2E_C}\right)^{1/4}\hat{\varphi}+2\mathrm{i}\left(\frac{2E_C}{E_J}\right)^{1/4}\hat{n}\\\hat{b}^\dagger&=\left(\frac{E_J}{2E_C}\right)^{1/4}\hat{\varphi}-2\mathrm{i}\left(\frac{2E_C}{E_J}\right)^{1/4}\hat{n}\end{align*}
$$

where $[\hat{b},\hat{b}^\dagger]=1$. Hence the operator $\hat{\varphi}$ and $\hat{n}$  can be expressed as

$$
\begin{align*}\hat{\varphi}&=\left(\frac{2E_C}{E_J}\right)^{1/4}(\hat{b}+\hat{b}^\dagger)\\\hat{n}&=\frac{\mathrm{i}}{2}\left(\frac{E_J}{2E_C}\right)^{1/4}(\hat{b}^\dagger-\hat{b})\end{align*}
$$

which verify that $\hat{\varphi}$ is a small quantity since $E_J\gg E_C$. Take them into the Hamiltonian

$$
\begin{align*}\hat{H}&\approx\hbar\omega\hat{b}^\dagger\hat{b}-\frac{E_C}{2}\hat{b}^\dagger\hat{b}^\dagger\hat{b}\hat{b}\\&=\hbar\omega_q\left(\hat{b}^\dagger\hat{b}\right)\hat{b}^\dagger\hat{b}\end{align*}
$$

where $\hbar\omega=\sqrt{8E_JE_C}-E_C$ and $\displaystyle \omega_q=\omega-\frac{E_C}{2\hbar}\left(\hat{b}^\dagger\hat{b}-1\right)$

[detailed process](details.md)

The energy level is

$$
E_n=n\hbar\omega-\frac{E_C}{2}n(n-1)
$$

The energy difference $|0\rangle\rightarrow|1\rangle$ and $|1\rangle\rightarrow|2\rangle$ are

$$
\begin{align*}\omega_{01}&=\omega\\\omega_{12}&=\omega-\frac{E_C}{\hbar}\end{align*}
$$

The nonlinearity of the system is defined as 

$$
\eta=\omega_{12}-\omega_{01}=-\frac{E_C}{\hbar}
$$

Generally, we choose 

$$
\begin{cases}\text{nonlinearity: }&\displaystyle-\frac{E_C}{h}\sim-0.25\text{ GHz}\\\\\text{bit frequence: }&\displaystyle\frac{\omega_{01}}{2\pi}\sim6\text{ GHz}\\\\\text{Josephson energy: }&\displaystyle \frac{E_J}{h}\sim 16\text{ GHz}\end{cases}
$$



# 4. Single Qubit Gates

<img src="fig\图片.png" alt="图片.png" style="zoom:45%;" />

The rotation operation

$$
X_\theta=R_X(\theta)=\mathrm{e}^{-\mathrm{i}\frac{\theta}{2}\sigma_x}=\cos{\frac{\theta}{2}}\mathbb{I}-\mathrm{i}\sin\frac{\theta}{2}\sigma_x
$$

Similar to the classical gates, all the quantum operation can be implemented by a set of quantum gates. A common set of universal gates is

$$
\mathcal{G_0}=\{X_\theta,Y_\theta,Z_\theta,\text{Ph}_\theta,\text{CNOT}\}
$$

Another universal gate set which is of particular interest from a theoretical perspective

$$
\mathcal{G_1}=\{H,S,T,\text{CNOT}\}
$$

Capacitive coupling between a resonator (or a feed-line) and the superconducting qubit dipole-field allows for microwave control to implement single-qubit rotations as well as certain two-qubit gates.

## 4.1 Capacitive coupling for X, Y control

<img src="fig\image%202.png" alt="image.png" style="zoom:40%;" />

Couple a microwave drive line [characterized by a time-dependent voltage $V_d(t)$] to a generic transmon-like superconducting qubit. The Hamiltonian is

$$
\begin{align*}H=\underbrace{\frac{\tilde{Q}^2}{2C_{\scriptscriptstyle{\sum}}}+\frac{\Phi^2}{2L}}_{LC}+\underbrace{\frac{C_\text{d}}{C_{\scriptscriptstyle{\sum}}}V_\text{d}\tilde{Q}}_{\text{coupling}}\end{align*}
$$

[deduce](deduce.md)

Assume there is only weak coupling to the drive-line ($C_d$ is a small quantity), so that $\tilde{Q}=\hat{Q}$. Utilize the annihilation operator

$$
\hat{Q}=\mathrm{i}\,e\left(\frac{E_J}{2E_C}\right)^{1/4}(\hat{b}^\dagger-\hat{b})=\mathrm{i}Q_{\text{zpf}}(\hat{b}^\dagger-\hat{b})
$$

The Hamiltonian can be expressed as

$$
\begin{align*}H=H_{\text{transmon}}+\mathrm{i}\frac{C_\text{d}}{C_{\scriptscriptstyle{\sum}}}V_\text{d}Q_{\text{zpf}}(\hat{b}^\dagger-\hat{b})\end{align*}
$$

Finally, by truncating to the lowest transition of the oscillator, we can make the replacement $\hat{b}=\sigma^{-},\,\hat{b}^{\dagger}=\sigma^{+}$

$$
H=\underbrace{-\hbar\frac{\omega_q}{2}\sigma_z}_{H_0}+\underbrace{\Omega V_d(t)\sigma_y}_{H_d}
$$

where $\hbar\omega_q=E_1-E_0$ , $\displaystyle\Omega=\frac{C_\text{d}}{C_{\scriptscriptstyle{\sum}}}Q_{\text{zpf}}$. To elucidate the role of the drive, we move into a frame rotating with the qubit at frequency $\omega_t$, the transformation is

$$
U_{\text{rf}}=U_{H_0}^{\dagger}=\mathrm{e}^{\mathrm{i}\frac{\omega_q}{2}\sigma_zt}
$$

The transformation of the Hamiltonian (utilize the BH formula)

$$
H_0\rightarrow U_{\text{rf}}H_0U_{\text{rf}}^{\dagger}+\mathrm{i}U_{\text{rf}}^\dagger U_{\text{rf}}=0
$$

and

$$
H_d\rightarrow U_{\text{rf}}H_0U_{\text{rf}}^{\dagger}=\Omega V_d(t)\left(\cos(\omega_q t)\sigma_y-\sin(\omega_qt)\sigma_x\right)
$$

In general, $V_d(t)$ is a narrow-band microwave pulse, and has the generic form $V_d=V_0\nu(t)$

$$
\begin{align*}\nu(t)&=s(t)\sin(\omega_dt+\phi)\\&=s(t)\big(\cos(\phi)  \sin(\omega_dt) + \sin(\phi) \cos(\omega_dt) \big)\end{align*}
$$

where $s(t)$ is a dimensionless envelope function, which represents the modulation of the wave packet shape. Adopting the definitions

$$
\begin{align*}I&=\cos\phi\quad\text{(the ‘in phase’ component)}\\Q&=\sin\phi\quad\text{(the ‘out of phase’ component)}\end{align*}
$$

The driving Hamiltonian in the rotating frame takes the form

$$
\tilde{H}_d=\Omega V_0s(t)\big(I  \sin(\omega_dt) + Q \cos(\omega_dt) \big)\times\left(\cos(\omega_q t)\sigma_y-\sin(\omega_qt)\sigma_x\right)
$$

Performing the multiplication and dropping fast rotating terms $(\omega_q+\omega_d)$ that will average to zero. Define $\delta\omega=\omega_q-\omega_d$

$$
\tilde{H}_d=\frac{1}{2}\Omega V_0s(t)\big[(-I\cos{(\delta\omega t)}+Q\sin(\delta\omega t))\sigma_x+(I\sin(\delta\omega t-Q\cos(\delta\omega t))\sigma_y)\big]
$$

In matrix form

$$
\tilde{H}_d=-\frac{\Omega}{2}V_0s(t)
\begin{pmatrix}
0&\mathrm{e}^{\mathrm{i(\delta\omega t+\phi)}}\\
\mathrm{e}^{-\mathrm{i(\delta\omega t+\phi)}}&0
\end{pmatrix}
$$

Assume that we apply a pulse at the qubit frequency, so that $\delta\omega=0$, then

$$
\tilde{H}_d=-\frac{\Omega}{2}V_0s(t)(I\sigma_x+Q\sigma_y)
$$

The corresponding unitary operator is so that

$$
U_{\text{rf,d}}^{\phi}=\exp\left(\left[\mathrm{i}\frac{\Omega}{2\hbar}V_0\int_{0}^{t}s(\tau)\mathrm{d}\tau\right]\cdot(I\sigma_x+Q\sigma_y)\right)
$$

which is known as “**Rabi driving**”

$$
\begin{cases}
\phi=0&\text{rotation around x-axis}\\\phi=\frac{\pi}{2}&\text{rotation around y-axis}
\end{cases}
$$

The rotating angle is

$$
\Theta=-\frac{\Omega}{\hbar}V_0\int_{0}^{t}s(\tau)\mathrm{d}\tau
$$

<img src="fig\image%203.png" alt="image.png" style="zoom:40%;" />

The microwave configuration

1. the local oscillator (LO) generate a low phase-noise microwave with frequency $\omega_{\text{LO}}$.
2. The AWG generate the pulse with $\omega_{\text{AWG}}$ and  dimensionless envelope function  $s(t)$.
3. Mix the two pulses with the microwave.

## 4.2 Virtual Z gate

This analogy between shifting a phase of an AWG-generated signal and applying Z rotations can be utilized to implement “virtual” Z gates.

Example:

$$
X_\theta^{(\phi_0)}X_\theta=\mathrm{e}^{-i\frac{\theta}{2}(\cos\phi_0\sigma_x+\sin\phi_0\sigma_y)}X_\theta=Z_{-\phi_0}X_\theta Z_{\phi_0}X_\theta
$$

which is same as the case that apply a $Z$ gate of $\phi_0$. The rear operation $Z_{-\phi_0}$ has no effect, since the readout is along the z-axis, a final phase rotation about z will not change the measurement outcome. Thus, if one wants to implement the gate sequence

<img src="fig\image%204.png" alt="image.png" style="zoom:35%;" />

this can be done by revising the gate sequence (in the control software for the AWG) and changing the phase of subsequent pulses

<img src="fig\image%205.png" alt="image.png" style="zoom:35%;" />

The virtual-Z gates are “perfect,” in the sense that no additional pulses are required, and the gate takes “zero time,” and thus the gate fidelity is nominally unity.

**Property**: Any single-qubit operation (up to a global phase) can be written as

$$
U(\theta,\phi,\lambda)=Z_{\phi-\frac{\pi}{2}}X_{\frac{\pi}{2}}Z_{\pi-\theta}X_{\frac{\pi}{2}}Z_{\lambda-\frac{\pi}{2}}
$$

Example: Hadamard gate

$$
H=Z_{\frac{\pi}{2}}X_{\frac{\pi}{2}}Z_{\frac{\pi}{2}}
$$

## 4.3 The DRAG scheme

We should notice that the high energy levels still exist even though we neglect them previous. This leads to two deleterious effects: 

1. leakage errors which take the qubit out of the computational subspace.
2. phase errors. 

Effect 1 can occur because a qubit in the state $|1\rangle$ may be excited to $|2\rangle$ as a p pulse is applied, or be excited directly from the $|0\rangle$, since the qubit spends some amount of time in the $|1\rangle$ state during the p pulse. Effect 2 occurs because the presence of the drive results in a repulsion between the $|1\rangle$ and $|2\rangle$ levels, in turn changing $\omega_q^{0\rightarrow1}$ as the pulse is applied.

The so-called DRAG procedure (Derivative Reduction by Adiabatic Gate) seeks to combat these two effects by applying an extra signal in the out-of-phase component.

$$
s(t)\rightarrow s'(t)=
\begin{cases}
s(t)&\text{on }I\\\\
\displaystyle\lambda\frac{\dot{s}(t)}{\alpha}&\text{on }Q
\end{cases}
$$

where $\alpha$ is the nonlinearity. The theoretically optimal choice for reducing dephasing error is $\lambda=0.5$ and an optimal choice for reducing leakage error is $\lambda=1$.

# 5. Double qubits gate

**Configuration**: the “q-c-q” system, where the LC resonator acts as a coupler to link the two qubits

<img src="fig\image%206.png" alt="image.png" style="zoom:25%;" />

## 5.1 Hamiltonian

The Hamiltonian of the system is

$$
H=\sum_i(\omega_ib_{i}^\dagger b_i+\frac{\eta_i}{2}b_{i}^\dagger b_{i}^\dagger b_{i} b_i)+\sum_{i<j}g_{ij}(b_i-b_i^{\dagger})(b_j-b_j^{\dagger})
$$