## Definitions

A Gaussian over $x\in{\mathbb{R}}^n$ with mean $a\in{\mathbb{R}}^n$ and
sym.pos.dev.&nbsp;covariance matrix $A\in{\mathbb{R}}^{n\times n}$ is
defined as:

$$\begin{align}
{\cal N}(x  \mkern-1pt \mid \mkern-1pt  a,A) &= \frac{1}{|2\pi A|^{1/2}}~ \exp\{-{\textstyle\frac{1}{2}}(x-a)^{\mkern-1pt \top \mkern-1pt}
A^\text{-1} (x-a)\} ~.
\end{align}$$

We also define a notation for its so-called *canonical form*, with
sym.pos.def.&nbsp;precision matrix $A\in{\mathbb{R}}^{n\times n}$, as

$$\begin{align}
{\cal N}[x  \mkern-1pt \mid \mkern-1pt  a,A]
 = \frac{\exp\{-{\textstyle\frac{1}{2}}a^{\mkern-1pt \top \mkern-1pt}A^\text{-1}a\}}{|2\pi A^\text{-1}|^{1/2}}~
   \exp\{-{\textstyle\frac{1}{2}}x^{\mkern-1pt \top \mkern-1pt}A x + x^{\mkern-1pt \top \mkern-1pt}a\} ~.
\end{align}$$

It holds

$$\begin{align}
& {\cal N}[x  \mkern-1pt \mid \mkern-1pt  a,A] = {\cal N}(x  \mkern-1pt \mid \mkern-1pt  A^\text{-1} a, A^\text{-1}) ~,\quad
 {\cal N}(x  \mkern-1pt \mid \mkern-1pt  a,A) = {\cal N}[x  \mkern-1pt \mid \mkern-1pt  A^\text{-1} a, A^\text{-1}] ~.
\end{align}$$

## Matrix Identities

As a background, here are matrix identities (based on the
[matrix-cookbook](https://www.math.uwaterloo.ca/~hwolkowi/matrixcookbook.pdf))
which are useful work with Gaussians:

$$\begin{align}
(A^\text{-1} + B^\text{-1})^\text{-1} &= A~ (A\!+\!B)^\text{-1}~ B = B~ (A\!+\!B)^\text{-1}~ A \\
(A^\text{-1} - B^\text{-1})^\text{-1} &= A~ (B\!-\!A)^\text{-1}~ B \\
\partial_x |A_x| &= |A_x|~ {\rm tr}(A_x^\text{-1}~ \partial_x A_x) \\
\partial_x A_x^\text{-1} &= - A_x^\text{-1}~ (\partial_x A_x)~ A_x^\text{-1} \\
(A+UBV)^\text{-1} &= A^\text{-1} - A^\text{-1} U (B^\text{-1} + VA^\text{-1}U)^\text{-1} V A^\text{-1} \label{wood}\\
(A^\text{-1}+B^\text{-1})^\text{-1} &= A - A (B + A)^\text{-1} A \\
(A + J^{\mkern-1pt \top \mkern-1pt}B J)^\text{-1} J^{\mkern-1pt \top \mkern-1pt}B 
&= A^\text{-1} J^{\mkern-1pt \top \mkern-1pt}(B^\text{-1} + J A^\text{-1} J^{\mkern-1pt \top \mkern-1pt})^\text{-1} \label{wood2}\\
(A + J^{\mkern-1pt \top \mkern-1pt}B J)^\text{-1} A
&= {\rm\bf I}- (A + J^{\mkern-1pt \top \mkern-1pt}B J)^\text{-1} J^{\mkern-1pt \top \mkern-1pt}B J  \label{null}
\end{align}$$

$\eqref{wood}$=Woodbury; $\eqref{wood2}$,$\eqref{null}$ hold for
pos.def.&nbsp;$A$ and $B$

## Derivatives

$$\begin{align}
\partial_x {\cal N}(x|a,A) &= {\cal N}(x|a,A)~ (-h^{\mkern-1pt \top \mkern-1pt})  ~,\quad h:= A^\text{-1}(x-a)\\
\partial_\theta{\cal N}(x|a,A)
&= {\cal N}(x|a,A)~ \Big[- h^{\mkern-1pt \top \mkern-1pt}(\partial_\theta x) 
   + h^{\mkern-1pt \top \mkern-1pt}(\partial_\theta a)
   - {\textstyle\frac{1}{2}}{\rm tr}(A^\text{-1}~ \partial_\theta A)
   + {\textstyle\frac{1}{2}}h^{\mkern-1pt \top \mkern-1pt}(\partial_\theta A) h \Big] \\
\partial_\theta{\cal N}[x|a,A]
& = {\cal N}[x|a,A]~ \Big[ -{\textstyle\frac{1}{2}}x^{\mkern-1pt \top \mkern-1pt}\partial_\theta A x + {\textstyle\frac{1}{2}}a^{\mkern-1pt \top \mkern-1pt}A^\text{-1} \partial_\theta A A^\text{-1} a 
+ x^{\mkern-1pt \top \mkern-1pt}\partial_\theta a - a^{\mkern-1pt \top \mkern-1pt}A^\text{-1} \partial_\theta a + {\textstyle\frac{1}{2}}{\rm tr}(\partial_\theta A A^\text{-1}) \Big]
\end{align}$$

## Product

The product of two Gaussians can be expressed as

$$\begin{align}
{\cal N}(x  \mkern-1pt \mid \mkern-1pt  a,A)~ {\cal N}(x  \mkern-1pt \mid \mkern-1pt  b,B)
 &= {\cal N}[x  \mkern-1pt \mid \mkern-1pt  A^\text{-1} a+B^\text{-1} b, A^\text{-1} + B^\text{-1}]~ {\cal N}(a \mkern-1pt \mid \mkern-1pt b,A+B) ~, \label{prodNat}\\
 &= {\cal N}(x  \mkern-1pt \mid \mkern-1pt  B(A\!+\!B)^\text{-1}a + A(A\!+\!B)^\text{-1}b ,A(A\!+\!B)^\text{-1}B)~ {\cal N}(a \mkern-1pt \mid \mkern-1pt b,A+B) ~,\\
{\cal N}[x  \mkern-1pt \mid \mkern-1pt  a,A]~ {\cal N}[x  \mkern-1pt \mid \mkern-1pt  b,B]
 &= {\cal N}[x  \mkern-1pt \mid \mkern-1pt  a+b,A+B]~ {\cal N}(A^\text{-1} a  \mkern-1pt \mid \mkern-1pt  B^\text{-1} b, A^\text{-1}+B^\text{-1}) \\
 &= {\cal N}[x  \mkern-1pt \mid \mkern-1pt  a+b,A+B]~ {\cal N}[ A^\text{-1} a  \mkern-1pt \mid \mkern-1pt  A(A\!+\!B)^\text{-1} b, A(A\!+\!B)^\text{-1} B]\\
 &= {\cal N}[x  \mkern-1pt \mid \mkern-1pt  a+b,A+B]~ {\cal N}[ A^\text{-1} a  \mkern-1pt \mid \mkern-1pt  (1\!-\!B(A\!+\!B)^\text{-1})~ b,~ (1\!-\!B(A\!+\!B)^\text{-1})~ B] ~,\\
{\cal N}(x  \mkern-1pt \mid \mkern-1pt  a,A)~ {\cal N}[x  \mkern-1pt \mid \mkern-1pt  b,B]
 &= {\cal N}[x  \mkern-1pt \mid \mkern-1pt  A^\text{-1} a+ b, A^\text{-1} + B]~ {\cal N}(a \mkern-1pt \mid \mkern-1pt B^\text{-1} b,A+B^\text{-1}) \\
 &= {\cal N}[x  \mkern-1pt \mid \mkern-1pt  A^\text{-1} a+ b, A^\text{-1} + B]~ {\cal N}[a \mkern-1pt \mid \mkern-1pt (1\!-\!B(A^\text{-1}\!+\!B)^\text{-1})~ b,~ (1\!-\!B(A^\text{-1}\!+\!B)^\text{-1})~
 B] \label{prodNatCan}
\end{align}$$

## Convolution

$$\begin{align}
\textstyle\int_x {\cal N}(x  \mkern-1pt \mid \mkern-1pt a,A)~ {\cal N}(y-x  \mkern-1pt \mid \mkern-1pt  b,B)~ dx
 &= {\cal N}(y  \mkern-1pt \mid \mkern-1pt  a+b, A+B)
\end{align}$$

## Division

$$\begin{align}
{\cal N}(x|&a,A) ~\big/~ {\cal N}(x|b,B) = {\cal N}(x|c,C) ~\big/~ {\cal N}(c| b, C+B) ~,\quad C^\text{-1}c = A^\text{-1}a - B^\text{-1}b,~ C^\text{-1} = A^\text{-1} - B^\text{-1} \\
{\cal N}[x|&a,A] ~\big/~ {\cal N}[x|b,B] \propto {\cal N}[x|a-b,A-B]
\end{align}$$

## Expectations

Let $x\sim{\cal N}(x  \mkern-1pt \mid \mkern-1pt  a,A)$, we have:

$$\begin{align}
&\mathbb{E}_{x}\!\left\{g(x)\right\} := \textstyle\int_x {\cal N}(x  \mkern-1pt \mid \mkern-1pt  a,A)~ g(x)~ dx \\
%&\Exp[x]{g(f+Fx)} = 
&\mathbb{E}_{x}\!\left\{x\right\} = a ~,\quad\mathbb{E}_{x}\!\left\{x x^{\mkern-1pt \top \mkern-1pt}\right\} = A + a a^{\mkern-1pt \top \mkern-1pt}\\
&\mathbb{E}_{x}\!\left\{f+Fx\right\} = f+Fa \\
&\mathbb{E}_{x}\!\left\{x^{\mkern-1pt \top \mkern-1pt}x\right\} = a^{\mkern-1pt \top \mkern-1pt}a + {\rm tr}(A)\\
&\mathbb{E}_{x}\!\left\{(x-m)^{\mkern-1pt \top \mkern-1pt}R(x-m)\right\} = (a-m)^{\mkern-1pt \top \mkern-1pt}R(a-m) + {\rm tr}(RA)
\end{align}$$

## Linear Transformation

For any $f\in{\mathbb{R}}^n$ and full-rank
$F\in{\mathbb{R}}^{n\times n}$, the following identities hold:

$$\begin{align}
{\cal N}(x \mkern-1pt \mid \mkern-1pt a,A) &= {\cal N}(x+f \mkern-1pt \mid \mkern-1pt a+f,~A) \\
{\cal N}(x \mkern-1pt \mid \mkern-1pt a,A) &= |F|~ {\cal N}(Fx  \mkern-1pt \mid \mkern-1pt  Fa,~FAF^{\mkern-1pt \top \mkern-1pt}) \\
{\cal N}(F x + f  \mkern-1pt \mid \mkern-1pt  a,A)
&= \frac{1}{|F|}~ {\cal N}(x  \mkern-1pt \mid \mkern-1pt  ~ F^\text{-1} (a-f),~ F^\text{-1} AF^{\text{-}\!\top})
 = \frac{1}{|F|}~ {\cal N}[x  \mkern-1pt \mid \mkern-1pt  ~ F^{\mkern-1pt \top \mkern-1pt}A^\text{-1} (a-f),~ F^{\mkern-1pt \top \mkern-1pt}A^\text{-1} F] ~, \\
{\cal N}[F x + f  \mkern-1pt \mid \mkern-1pt  a,A]
&= \frac{1}{|F|}~ {\cal N}[x  \mkern-1pt \mid \mkern-1pt  ~ F^{\mkern-1pt \top \mkern-1pt}(a-Af),~ F^{\mkern-1pt \top \mkern-1pt}A F] ~.
\end{align}$$

## "Propagation"

Propagating a message along a linear coupling (e.g.&nbsp;forward model),
using eqs $\eqref{prodNat}$ and $\eqref{prodNatCan}$, respectively, we
have:

$$\begin{align}
& \textstyle\int_y {\cal N}(x  \mkern-1pt \mid \mkern-1pt  a + Fy, A)~ {\cal N}(y  \mkern-1pt \mid \mkern-1pt  b, B)~ dy
 = {\cal N}(x  \mkern-1pt \mid \mkern-1pt  a + Fb, A+FBF^{\mkern-1pt \top \mkern-1pt}) \\
& \textstyle\int_y {\cal N}(x  \mkern-1pt \mid \mkern-1pt  a + Fy, A)~ {\cal N}[y  \mkern-1pt \mid \mkern-1pt  b, B]~ dy
 = {\cal N}[x  \mkern-1pt \mid \mkern-1pt  (F^{\text{-}\!\top}\!-\!K)(b+BF^\text{-1}a),~ (F^{\text{-}\!\top}\!-\!K)BF^\text{-1}] ~,
\end{align}$$

where
$K=F^{\text{-}\!\top}B(F^{\text{-}\!\top}A^\text{-1} F^\text{-1}\!+\!B)^\text{-1}$.

## Marginal & Conditional

$$\begin{align}
{\cal N}(x  \mkern-1pt \mid \mkern-1pt  a,A)~ {\cal N}(y  \mkern-1pt \mid \mkern-1pt  b+Fx,B)
 &= {\cal N}\bigg(  \begin{array}{c}x\\ y\end{array}  \bigg|  \begin{array}{c}a\\ b+Fa\end{array}  ,~
              \begin{array}{cc}A & A^{\mkern-1pt \top \mkern-1pt}F^{\mkern-1pt \top \mkern-1pt}\\ F A & B\!+\!F A^{\mkern-1pt \top \mkern-1pt}F^{\mkern-1pt \top \mkern-1pt}\end{array}  \bigg) \\
%
{\cal N}\bigg(  \begin{array}{c}x\\ y\end{array}  \bigg|  \begin{array}{c}a\\ b\end{array}  ,~ 
          \begin{array}{cc}A & C\\ C^{\mkern-1pt \top \mkern-1pt}& B\end{array}  \bigg)
&= {\cal N}(x  \mkern-1pt \mid \mkern-1pt  a,A) \cdot {\cal N}(y  \mkern-1pt \mid \mkern-1pt  b+C^{\mkern-1pt \top \mkern-1pt}A^\text{-1}(x-a),~ B - C^{\mkern-1pt \top \mkern-1pt}A^\text{-1} C) \\
%
{\cal N}[ x  \mkern-1pt \mid \mkern-1pt  a,A ]~ {\cal N}(y  \mkern-1pt \mid \mkern-1pt  b+Fx,B )
 &= {\cal N}\bigg[  \begin{array}{c}x\\ y\end{array}  \bigg|  \begin{array}{c}a+F^{\mkern-1pt \top \mkern-1pt}B^\text{-1} b \\ B^\text{-1} b\end{array}  ,~
              \begin{array}{cc}A+F^{\mkern-1pt \top \mkern-1pt}B^\text{-1} F & -F^{\mkern-1pt \top \mkern-1pt}B^\text{-1} \\ -B^\text{-1} F & B^\text{-1}\end{array}  \bigg] \\
%
{\cal N}[x  \mkern-1pt \mid \mkern-1pt  a,A ]~ {\cal N}[y  \mkern-1pt \mid \mkern-1pt  b+Fx,B ]
 &= {\cal N}\bigg[  \begin{array}{c}x\\ y\end{array}  \bigg|  \begin{array}{c}a+F^{\mkern-1pt \top \mkern-1pt}B^\text{-1} b \\ b\end{array}  ,~
              \begin{array}{cc}A+F^{\mkern-1pt \top \mkern-1pt}B^\text{-1}  F & -F^{\mkern-1pt \top \mkern-1pt}\\ -F & B\end{array}  \bigg] \\
%
{\cal N}\bigg[  \begin{array}{c}x\\ y\end{array}  \bigg|  \begin{array}{c}a\\ b\end{array}  ,~ 
          \begin{array}{cc}A & C\\ C^{\mkern-1pt \top \mkern-1pt}& B\end{array}  \bigg]
&= {\cal N}[x  \mkern-1pt \mid \mkern-1pt  a - C B^\text{-1} b,~ A - C B^\text{-1} C^{\mkern-1pt \top \mkern-1pt}] \cdot {\cal N}[y  \mkern-1pt \mid \mkern-1pt  b-C^{\mkern-1pt \top \mkern-1pt}x,B] \\
\left| \begin{array}{cc}A&C\\D&B\end{array} \right|
 &= |A|~ |\widehat B| = |\widehat A|~ |B| ~,
 \text{where }  \begin{array}{l} \widehat A = A - C B^\text{-1} D \\ \widehat B = B - D A^\text{-1} C \end{array} \\
\left[ \begin{array}{cc}A&C\\D&B\end{array} \right]^\text{-1}
 &= \left[ \begin{array}{cc}\widehat A^\text{-1}&-A^\text{-1} C \widehat B^\text{-1}\\-\widehat B^\text{-1} D A^\text{-1}&\widehat B^\text{-1}\end{array} \right]
 = \left[ \begin{array}{cc}\widehat A^\text{-1}&-\widehat A^\text{-1} C B^\text{-1}\\-B^\text{-1} D \widehat A^\text{-1}&\widehat B^\text{-1}\end{array} \right]
\end{align}$$

## Pair-wise Belief

We have a message
$\alpha(x)={\cal N}[x  \mkern-1pt \mid \mkern-1pt  s,S]$, transition
$P(y|x) = {\cal N}(y  \mkern-1pt \mid \mkern-1pt  A x+a,Q)$, and a
message $\beta(y)={\cal N}[y  \mkern-1pt \mid \mkern-1pt  v,V]$, what is
the belief $b(y,x)=\alpha(x)P(y|x)\beta(y)$?

$$\begin{align}
b(y,x)
 &= {\cal N}[x|s,S]~ {\cal N}(y|A x+a,Q^\text{-1})~ {\cal N}[y|v,V] \\
&=
{\cal N}\bigg[  \begin{array}{c}x\\ y\end{array}  \bigg|  \begin{array}{c}s \\ 0\end{array}  ,~
              \begin{array}{cc}S & 0 \\ 0 & 0\end{array}  \bigg]~~~
{\cal N}\bigg[  \begin{array}{c}x\\ y\end{array}  \bigg|  \begin{array}{c}A^{\mkern-1pt \top \mkern-1pt}Q^\text{-1} a \\ Q^\text{-1} a\end{array}  ,~
              \begin{array}{cc}A^{\mkern-1pt \top \mkern-1pt}Q^\text{-1} A & -A^{\mkern-1pt \top \mkern-1pt}Q^\text{-1} \\ -Q^\text{-1} A & Q^\text{-1}\end{array}  \bigg]~~~
{\cal N}\bigg[  \begin{array}{c}x\\ y\end{array}  \bigg|  \begin{array}{c}0 \\ v\end{array}  ,~
              \begin{array}{cc}0 & 0 \\ 0 & V\end{array}  \bigg] \\
&\propto
{\cal N}\bigg[  \begin{array}{c}x\\ y\end{array}  \bigg|  \begin{array}{c}s + A^{\mkern-1pt \top \mkern-1pt}Q^\text{-1} a\\ v + Q^\text{-1} a\end{array}  ,~
              \begin{array}{cc}S + A^{\mkern-1pt \top \mkern-1pt}Q^\text{-1} A & -A^{\mkern-1pt \top \mkern-1pt}Q^\text{-1} \\ -Q^\text{-1} A & V+Q^\text{-1}\end{array}  \bigg]
\end{align}$$

## Entropy

$$\begin{align}
H({\cal N}(a,A)) &= {\textstyle\frac{1}{2}}\log |2\pi e A|
\end{align}$$

## Kullback-Leibler divergence

For $p={\cal N}(x|a,A),~ q={\cal N}(x|b,B), n = \text{dim}(x)$ and
definition
$D\big(p\,\big\Vert\,q\big) = \sum_x p(x) \log\frac{p(x)}{q(x)}$, we
have:

$$\begin{align}
2~ D\big(p\,\big\Vert\,q\big)
&= \log\frac{|B|}{|A|} + {\rm tr}(B^\text{-1}A) + (b-a)^{\mkern-1pt \top \mkern-1pt}B^\text{-1} (b-a) - n \\
4~ D_\text{sym}\big(p \,\big\Vert\, q\big)
&= {\rm tr}(B^\text{-1}A) + {\rm tr}(A^\text{-1}B) + (b-a)^{\mkern-1pt \top \mkern-1pt}(A^\text{-1}+B^\text{-1}) (b-a) - 2n
\end{align}$$

$\lambda$-divergence:

$$\begin{align}
2~ D_\lambda\big(p \,\big\Vert\, q\big)
&= \lambda~ D\big(p\,\big\Vert\,\lambda p+(1\!-\!\lambda)q\big) ~+~ (1\!-\!\lambda)~ D\big(p\,\big\Vert\,(1\!-\!\lambda) p + \lambda q\big)
\end{align}$$

For $\lambda=.5$: Jensen-Shannon divergence.

## Log-likelihoods

$$\begin{align}
\log {\cal N}(x|a,A)
 &= - {\textstyle\frac{1}{2}}\Big[ \log|2\pi A| + (x-a)^{\mkern-1pt \top \mkern-1pt}A^\text{-1} (x-a) \Big] \\
\log {\cal N}[x|a,A]
 &= - {\textstyle\frac{1}{2}}\Big[ \log|2\pi A^\text{-1}| + a^{\mkern-1pt \top \mkern-1pt}A^\text{-1} a + x^{\mkern-1pt \top \mkern-1pt}A x - 2 x^{\mkern-1pt \top \mkern-1pt}a \Big] \\
\sum_x {\cal N}(x|b,B) \log {\cal N}(x|a,A)
 &= -D\big({\cal N}(b,B)\,\big\Vert\,{\cal N}(a,A)\big) - H({\cal N}(b,B))
\end{align}$$

## Mixture of Gaussians

&nbsp; Collapsing a MoG into a single Gaussian

$$\begin{align}
&\text{argmin}_{b,B} D\big(\sum_i p_i~ {\cal N}(a_i,A_i)\,\big\Vert\,{\cal N}(b,B)\big)
\quad=\quad\Big(
b=\sum_i p_i a_i ~,~
B=\sum_i p_i (A_i + a_i a_i^{\mkern-1pt \top \mkern-1pt}- b\, b^{\mkern-1pt \top \mkern-1pt})\Big)
\end{align}$$
