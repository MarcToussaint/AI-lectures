$\text{SO}(2)$ is the space of rotations in the plane ${\mathbb{R}}^2$
(or about a single axis), which can be described by an angle
$\alpha\in[0,2\pi]$. But there are good arguments to instead represent
such rotations by a point on $S^1$, which is the circle in
${\mathbb{R}}^2$. E.g., topologically $\text{SO}(2)$ is equal to $S^1$
and not to the interval $[0,2\pi]$. Points in $S^1$ can also be
described as $e^{i\alpha} \in{\mathbb{C}}$, which is the circle in the
complex plane. Quaternions similarly represent rotations of
$\text{SO}(3)$ as points on $S^3$, i.e., the sphere in ${\mathbb{R}}^4$.
And just as $e^{i\alpha} \in{\mathbb{C}}$ gives points on the circle
$S^1$, the exponential map of $\text{SO}(3)$ gives defines quaternions
on $S^3$.

The following will first provide reference equations for quaternions,
but then explain in more detail interpolation between rotations, which
naturally introduces the exponential map directly for quaternions
without need to go deeper into Lie groups. An emphasis is then on
deriving the *quaternion Jacobian*, which describes the angular velocity
that is induced when perturbing a quaternion parameter.

Reference
=========

Let&rsquo;s define a quaternion $q\in{\mathbb{R}}^4$ as a 4-vector.[^1]
To represent a rotation, a quaternion needs to be normalized, i.e.,
$q\in S^3$. We denote the first entry by $q_0$ and the last three
entries by $\bar q\equiv q_{1:3} \in{\mathbb{R}}^3$. Let&rsquo;s first
summarize some basic properties for a normalized quaternion:

$$\begin{align}
\text{rotation angle $\theta\in{\mathbb{R}}$:} \quad \label{eqAngle}
& \theta= 2 \mathop{\mathrm{acos}}(q_0) = 2\, \text{asin}(|\bar q|) \\
\text{normalized axis $\widehat w\in S^2$:} \quad \label{eqAxis}
& \widehat w = \textstyle\frac{\bar q}{|\bar q|} = \textstyle\frac{1}{\sin(\theta/2)} \bar q \\
\text{rotation vector $w\in{\mathbb{R}}^3$:} \quad \label{eqLog}
& w = \log(q) = 2 \mathop{\mathrm{acos}}(q_0)~ \textstyle\frac{\bar q}{|\bar q|}  \\
\text{quat. from vector $w=\theta\widehat w$:} \quad \label{eqExp}
& q = \exp(w) = (\cos(\theta/2),~ \sin(\theta/2)~ \widehat w) \\
\text{rotation matrix $R\in{\mathbb{R}}^{3\times 3}$:} \quad \label{eqMatrix}
& R
=  \left(\begin{array}{ccc}
    1-q_{22}-q_{33} & q_{12}-q_{03} &    q_{13}+q_{02} \\
    q_{12}+q_{03} &   1-q_{11}-q_{33} &  q_{23}-q_{01} \\
    q_{13}-q_{02} &   q_{23}+q_{01} &    1-q_{11}-q_{22}
    \end{array}\right) ,~ q_{ij} := 2 q_i q_j \\
\text{quaternion from matrix:} \quad
& q_0 = \textstyle\frac 12 \sqrt{1+{\rm tr}R},~
  q_1 = \textstyle\frac{R_{32}-R_{23}}{4 q_0},~
  q_2 = \textstyle\frac{R_{13}-R_{31}}{4 q_0},~
  q_3 = \textstyle\frac{R_{21}-R_{12}}{4 q_0}  \\
\text{quaternion inverse:} \quad
& q^{-1} = (q_0,-\bar q) \quad \text{or} \quad  q^{-1} = (-q_0, \bar q) \\
\text{quaternion concatenation:} \quad &
q \circ q'
 = (q_0 q'_0 - \bar q^{\mkern-1pt \top \mkern-1pt}\bar q',~
    q_0 \bar q' + q'_0 \bar q + \bar q \times \bar q') \\
\text{vector application, $x\in{\mathbb{R}}^3$:} \quad \label{eqApp}
& q \cdot x = (q \circ (0,x) \circ q^{-1})_{1:3} \quad\text{(or via matrix)}
\end{align}$$

Eqs.&nbsp;$\eqref{eqLog}$ and $\eqref{eqExp}$ follow from
$\eqref{eqAngle}$ and $\eqref{eqAxis}$, but why they are defined as
&rsquo;log&rsquo; and &rsquo;exp&rsquo; will become clear below.
Concerning the application of a rotation quaternion $q$ on a vector $x$,
equation $\eqref{eqApp}$ is elegant, but computationally less efficient
than first converting to matrix using $\eqref{eqMatrix}$ and then
multiplying to the vector. Note that concatenating quaternions as well
as applying a quaternion to a vector never requires to compute a $\sin$
or $\cos$, as opposed, e.g. to the Rodriguez&rsquo; equation (see
below).

Continuously moving from $I$ to $q$ &ndash; exponential and log mappings
========================================================================

Given a quaternion $q$, how can we continuously move from the
${\rm\bf I}=(1,\bar
0)$ to $q$? The answer is simply given by continuously increasing the
rotation angle $\eqref{eqAngle}$ from $0$ to $\theta$. Let
$t\in[0,\theta]$ be the interpolation coefficient, we have

$$\begin{align}
q(t)
&= (\cos(t/2),~ \sin(t/2)~ \widehat w) ~. \label{eqExp0}
\end{align}$$

This "motion" from ${\rm\bf I}$ to $q$ is a geodesic (=shortest path) on
$S^3$ (w.r.t. to the natural embedded Euclidean metric of
${\mathbb{R}}^4$), and it has constant absolute velocity:

$$\begin{align}\label{eqVel}
\dot q(t)
&= (-\sin(t/2),~ \cos(t/2)~ \widehat w)~,\quad
|\dot q(t)| = \textstyle\frac 12 ~.
\end{align}$$

At the origin (for $t=0$), the velocity is
$\dot q(0) = \textstyle\frac 12 (0, \widehat w)$, which shows how the
rotation axis $\widehat w$ provides the tangent vector at ${\rm\bf I}$.
For $t>0$ the velocity $\eqref{eqVel}$ "rotates along the tangent arc"
on $S^3$. We can show that $\dot q(t)$ can also be written as (using
that $\widehat w$ and $\bar q(t)$ are colinear):

$$\begin{align}
\textstyle\frac 12 (0, \widehat w) \circ q(t)
&= \textstyle\frac 12 (0 q_0(t) - \widehat w^{\mkern-1pt \top \mkern-1pt}\bar q(t),~ 0 \bar q(t) + q_0(t) \widehat w + \widehat w \times \bar q(t)) \\
&= \textstyle\frac 12 (0 - \sin(t/2),~ \cos(t/2)~ \widehat w + 0) ~=~ \dot q(t) ~.  \label{eqDotq}
\end{align}$$

Eq.&nbsp;$\eqref{eqDotq}$ is a differential equation of the form
$\dot q(t)
= \alpha q(t)$, but with the multiplication being the group operation
$\circ$. The solution $q(t)$ to this differential equation is defined as
the exponential map.[^2] Namely, for a vector $w=t\widehat w \in
{\mathbb{R}}^3$ we define

$$\begin{align}
\exp(t \widehat w)
&= (\cos(t/2),~ \sin(t/2)~ \widehat w) ~,\quad
\Rightarrow~ \frac{\partial}{\partial t} \exp(t \widehat w)
 = \textstyle\frac 12 (0, \widehat w) \circ \exp(t \widehat w) ~,
\end{align}$$

fully consistent to $\eqref{eqExp0}$ and $\eqref{eqDotq}$. Conversely,
given a quaternion, we define the log as

$$\begin{align}
\log(q)
&= 2 \mathop{\mathrm{acos}}(q_0)~ \textstyle\frac{\bar q}{|\bar q|} ~.
\end{align}$$

Continuously moving from $q_A$ to $q_B$ &ndash; interpolation in quaternion space
=================================================================================

Consider two quaternions $q_A, q_B$. When concatenating
$q_B = q_{BA} \circ q_A$, you should think of $q_{BA}$ as describing an
"additional" rotation in the output coordinates of $q_A$. This is
exactly as multiplying matrices $R_B = R_{BA} R_A$, where $R_{BA}$
describes a rotation from orientation $R_A$ to orientation $R_B$. The
relative rotation $q_B / q_A \equiv q_B \circ q_A^{-1} = q_{BA}$
retrieves exactly this relative rotation from $q_A$ to $q_B$.

There are two ways to interpolate between orientations $q_A$ and $q_B$.
Let $t\in[0,1]$. The *proper* interpolation uses the exponential map:

$$\begin{align}
q(t) = \exp(t\log(q_B/q_A)) \circ q_A ~. \label{eqInter}
\end{align}$$

This first computes the relative transform $q_{BA} = q_B/q_A$, computes
its tangent vector representation $\log(q_{BA})$, and interpolates from
${\rm\bf I}$ to $q_{BA}$ as we described above. Finally it multiplies
$q_A$ from the right, making all this relative to orientation $q_A$. For
completeness, the velocity is

$$\begin{align}
\dot q(t)
&= \Big[\frac{\partial}{\partial t} \exp(t\log(q_B/q_A))\Big] \circ q_A \\
&= \Big[\textstyle\frac 12 (0, w_{BA}) \circ \exp(t\log(q_B/q_A))\Big] \circ q_A \\
&= \textstyle\frac 12 (0, w_{BA}) \circ q(t) ~. \label{eqInterVel}
\end{align}$$

As an alternative, we can define the *embedded* interpolation as

$$\begin{align}
q(t) = \text{normalize}((1-t)~ q_A + t~ q_B) ~, \label{eqLinInter}
\end{align}$$

where $\text{normalize}(q) = q / |q|$. This assumes that the two
quaternions are *sign aligned*, i.e.
$q_A^{\mkern-1pt \top \mkern-1pt}q_B \ge 0$. This interpolation seems
native. However, it describes the exact same *path* as the proper
interpolation: along the geodesic arc on $S^3$ from $q_A$ to $q_B$. The
only difference is that it does not have constant absolute velocity on
$S^3$. The non-normalized interpolation $(1-t) q_A + t q_B$ in
${\mathbb{R}}^4$ has constant velocity, but the projection to $S^3$
modulates velocities depending on the angle of the tangent space to the
embedded interpolation. But note that, as
$q_A^{\mkern-1pt \top \mkern-1pt}q_B \ge 0$, the angle between $q_A$ and
$q_B$ in ${\mathbb{R}}^4$ is at most 90 degrees; and therefore the angle
between the linear interpolation and the tangent spaces is at most 45
degrees &ndash; in this worst case, the velocities at start and end are
by a factor $1/\sqrt{2}$ larger than in the middle.

The point here is that interpolation of rotations is very intuitive:
"straight" interpolation on the sphere $S^3$ which can equally described
using $\eqref{eqLinInter}$ (with the exponential map) or the naive
embedded interpolation $\eqref{eqLinInter}$. But only the proper
interpolation with the exponential map has constant absolute velocity.

Angular Jacobian w.r.t. Quaternion Parameters
=============================================

Assume we have a quaternion $q\in{\mathbb{R}}^4$ as a *parameter* of
some optimization problem and need a Jacobian w.r.t. $q$. More
concretely, we want to know the angular velocity $w = J \dot q$ that is
induced by a velocity (or infinitesimal variation) of $q$. To relate to
Eq.&nbsp;$\eqref{eqInterVel}$ we think of $q=q_A$ as the base
orientation, and $\dot q$ as moving from $q_A$ to $q_B$.
Eq.&nbsp;$\eqref{eqInterVel}$ for $t=0$ becomes

$$\begin{align}
\dot q &= \textstyle\frac 12 (0, w) \circ q ~.
\end{align}$$

This equation holds if $\dot q$ is tangential to $S^3$, and translates
$\dot q$ to an angular vector $w\in{\mathbb{R}}^3$ *relative* to the
orientation $q$ (just how $w_{BA}$ was the angular vector relative to
the base orientation $q_A$). Under these tangential assumptions, we can
directly read out $w$ by multiplying $q^{-1}$ from the right,

$$\begin{align}
\dot q \circ q^{-1}
&= {\frac{1}{2}}(0,w) ~,\quad w = 2~ [\dot q \circ q^{-1}]_{1:3} ~.
\end{align}$$

However, in the case where $\dot q$ is non-tangential, i.e.,
$\dot q^{\mkern-1pt \top \mkern-1pt}q \not=0$, the change in length of
the quaternion does not represent any angular velocity. One approach is
to first tangentialize
$\dot {\widehat q} = \dot q - q q^{\mkern-1pt \top \mkern-1pt}\dot q$.
However, when pluging in the tangentialized $\dot{\widehat q}$ we get

$$\begin{align}
w
&= 2~ [(\dot q - (q^{\mkern-1pt \top \mkern-1pt}\dot q) q)  \circ q^{-1}]_{1:3} \\
&= 2~ [\dot q \circ q^{-1}]_{1:3} - 2~ (q^{\mkern-1pt \top \mkern-1pt}\dot q) [q \circ q^{-1}]_{1:3} ~,
\end{align}$$

and the latter term is identically zero. So, our "tangentialization
term" drops out anyway.

To construct the Jacobian, let&rsquo;s assume $\dot q=e_i$ is one of the
unit vectors $e_0,..,e_3\in{\mathbb{R}}^4$. Then we have

$$\begin{align}
w_i
&= 2~ [e_i\circ q^{-1}]_{1:3} ~.
\end{align}$$

Further, if $q$ itself was not normalized we want the angular Jacobian
of $\widehat q = \textstyle\frac 1{|q|} q$ w.r.t. $q$. As the above
relation between $q$ and $w$ is linear, we have

$$\begin{align}
w_i
&= \textstyle\frac 2{|q|}~ [e_i \circ \widehat q^{-1}]_{1:3} ~.
\end{align}$$

Based on this we construct the **angular quaternion Jacobian** with 4
columns

$$\begin{align}
J_{\cdot i}(q) = \textstyle\frac 2{|q|}~ [e_i \circ \widehat q^{-1}]_{1:3} ~,
\end{align}$$

so that we have $w = J(q)~ \dot q$ for any (also non-normalized,
non-tangential) $q$ and $\dot q$.

Again, note that this angular vector $w$ is to be interpreted *relative*
to $q$, in the output space of $q$. To translate this to a world
coordinate angular Jacobian, we need to transform by $q$ again. To give
a more complete example: if we have a pose
$q_B = \text{normalize}(q) \circ q_A$ that is parameterized by arbitrary
(non-zero) $q\in{\mathbb{R}}^4$, then $\dot
q$ translates to a world coordinate angular velocity $w = q_B \cdot
J(q) \dot q$ of the pose of $B$.

Random rotations & "Gaussians"
==============================

To get a random rotation, we want to uniformly sample from $S^3$. This
is particularly easy by first sampling $q\sim{\mathbb{N}}(0,1)$ in
${\mathbb{R}}^4$ and then normalize.

To sample a rotation "Gaussian around a mean" quaternion $q$, we have
two options (akin to the interpolation options): The tangent space
sampling:

$$\begin{align}
q' = \exp(w) \circ q~,\quad w = {\cal N}(0,\sigma^2) \in {\mathbb{R}}^3 ~,
\end{align}$$

or

$$\begin{align}
q' = \text{normalize}(q + \delta/2)~,\quad\delta= {\cal N}(0,\sigma^2) \in {\mathbb{R}}^4 ~.
\end{align}$$

In the limit of small $\sigma^2$ these become the same, as the Gaussian
projected to the tangent space is the same as the Gaussian in the
tangent space.

Similarly: Rotation vector and angular velocity
===============================================

To recap, a rotation vector is $w\in{\mathbb{R}}^3$, with rotation axis
$\widehat w
= \frac{w}{|w|}$, and rotation angle $\theta= |w|$ (in radians, using
the right thumb convention).

The application of a rotation described by $w\in{\mathbb{R}}^3$ on a
vector $x\in{\mathbb{R}}^3$ is given as (Rodrigues&rsquo; formula)

$$\begin{align}
w \cdot x
 &= \cos(\theta)~ x
  + \sin(\theta)~ (\widehat w\times x)
  + (1-\cos(\theta))~ \widehat w(\widehat w^{\mkern-1pt \top \mkern-1pt}x) ~.
\end{align}$$

This directly also implies convertion to a rotation matrix, as the rows
of the corresponding rotation matrix are simply $w \cdot e_i$ for the
unit vectors $e_{1:3}\in{\mathbb{R}}^3$. To simplify the notation, we
define the skew matrix of a vector $w\in{\mathbb{R}}^3$ as

$$\begin{align}
\text{skew}(w) =  \left(\begin{array}{ccc}0 & -w_3 & w_2 \\ w_3 & 0 & -w_1 \\ -w_2 & w_1 & 0\end{array}\right)  ~.
\end{align}$$

This allows to express the cross product as matrix multiplication,
$w \times v = \text{skew}(w)~ v$. The rotation matrix $R(w)$
corresponding to a given rotation vector $w$ then is:

$$\begin{align}\label{eqRodriguez}
R(w)
 &= \exp(\text{skew}(w)) \\
 &= \cos(\theta)~ {\rm\bf I}+ \sin(\theta)/\theta~ \text{skew}(w) + (1-\cos(\theta))/\theta^2~ w w^{\mkern-1pt \top \mkern-1pt}
\end{align}$$

The $\exp$ function is called exponential map (generating a group
element (=rotation matrix) via an element of the Lie algebra (=skew
matrix)). The other formular is called Rodrigues&rsquo; formular: the
first term is a diagonal matrix (${\rm\bf I}$ is the 3D identity
matrix), the second terms the skew symmetric part, the last term the
symmetric part ($w
w^{\mkern-1pt \top \mkern-1pt}$ is also called outper product).

**Angular velocity & derivative of a rotation matrix:** We represent
angular velocities by a vector $w\in{\mathbb{R}}^3$, with rotation axis
$\widehat w$, and rotation velocity $|w|$ (in radians per second). When
a body&rsquo;s orientation at time $t$ is described by a rotation matrix
$R(t)$ and the body&rsquo;s angular velocity is $w$, then

$$\begin{align}\label{eqDotR}
\dot R(t) = \text{skew}(w)~ R(t)~.
\end{align}$$

(That&rsquo;s intuitive to see for a rotation about the $x$-axis with
velocity 1.) Some insights from this relation: Since $R(t)$ must always
be a rotation matrix (fulfill orthogonality and determinant 1), its
derivative $\dot R(t)$ must also fulfill certain constraints; in
particular it can only live in a 3-dimensional sub-space. It turns out
that the derivative $\dot R$ of a rotation matrix $R$ must always be a
skew symmetric matrix $\text{skew}(w)$ times $R$ &ndash; anything else
would be inconsistent with the contraints of orthogonality and
determinant 1.

Note also that, assuming $R(0)=I$, the solution to the differential
equation $\dot R(t) = \text{skew}(w)~ R(t)$ can be written as
$R(t)=\exp(t~ \text{skew}(w))$, where here the exponential function
notation is used to denote a more general so-called exponential map, as
used in the context of Lie groups. It also follows that $R(w)$ from
$\eqref{eqRodriguez}$ is the rotation matrix you get when you rotate for
1 second with angular velocity described by $w$.

[^1]: In the original meaning, they are defined as
    $q = q_0 + q_1 i + q_2 j + q_3
    k$, with $j,k$ being extensions to the imaginary number $i$. But we
    just treat them as 4-vectors.

[^2]: When describing $\text{SO}(3)$ as a Lie groups, analogous
    equations appear when tangent motion is integrated to continuously
    move to group elements. The solutionis defined as $\exp(\cdot)$ of a
    tangent vector.
