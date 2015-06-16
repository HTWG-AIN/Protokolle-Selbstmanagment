<html>
<head>
<meta content="text/html; charset=utf-8" http-equiv="Content-Type" /> <style> * { color: #ddd; background-color: #222; font-family: ubuntu, Tahoma, Verdana, Segoe, sans-serif; line-height: 100%; } em { color: turquoise; } p { padding-left: 40px;
} h2 { padding-left: 10px; } h3 { padding-left: 20px; } h4 { padding-left: 30px; } h5 { padding-left: 40px; } h6 { padding-left: 50px; } ol,ul { padding-left: 60px; } ol ul { padding-left: 20px; } ul ol { padding-left: 20px; } h1 { text-decoration:underline;
border-bottom: 1px solid #000; } table { padding-left: 40px; border-collapse: collapse; table-layout: fixed; } td { padding: 5px; text-align: center; border: 1px solid #eee; overflow: hidden; } </style> <script type="text/x-mathjax-config"> MathJax.Hub.Config({ tex2jax: { inlineMath: [ ['$','$'], ["\(","\)"] ], processEscapes: true } }); </script> <script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=default"></script> 
</head> 
<body>

Übungsaufgaben Theoretische Informatik
--------------------------------------

###### Prof. Dr. Ulrich Hedtstück

###### Informatik, SS 2015

### **Übungsblatt 2**

**Aufgabe 1**

*Bemerkungen* 

1- DEA : von jedem Zustand gibts genau nur einen Übergang $(q,a,q')$ (oder auch kein Pfeil), und wenn es für einen Zustand 2 Übergänge gsibt und für den anderen nur einen dann tun wir Papierkorbzustand legen.

2- NEA : hat Zustände $\lt \infty$ und genau einen Anfangzustand

a)b)c)d) : siehe handout (NEA)

**Aufgabe 2**

siehe handout.

**Aufgabe 3**

Als Grammatik folgendes aber wir brauchen Ausdruck (das ist was anders): 

$Z = \{A,B,C,D,E\}$

$V = \{a,b\}$

$q_M = A$

$F = \{A\}$
$$ \delta = \\
A,a,C\\
B,a,D\\
B,b,A\\
C,a,E\\
C,b,B\\
D,b,C\\
E,b,C
$$
$$P = \\ A \rightarrow aC \\
      B \rightarrow aD \ | \ b \\
      C \rightarrow aE \ | \ bE \\
      D \rightarrow bC \\
      E \rightarrow bD $$
_________________________________________________________________

$$
T(M) = (a((abb|bab)^* bb))^*
$$

**Aufgabe 4**

siehe handout.

**Aufgabe 5**

$\{0,1\}^*$ ist regulär (s. handout) 

$\{0^n 1^n | n \gt 1\} \in \{0,1\}$

**Aufgabe 6**

siehe handout !

**Aufgabe 7**

**Choice Test**

1- richtig

2- richtig

3- richtig

4-

5-

6-

7-





















</body> </html>
