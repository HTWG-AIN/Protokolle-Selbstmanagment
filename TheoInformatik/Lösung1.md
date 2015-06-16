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

### **Übungsblatt 1**

**Aufgabe 1**

**Reguläre Grammatik**

- [a]  L beginnt mit einer ungeraden Anzahl Nullen und folgt von einer
    geraden Anzahl Einsen \
    
    $\{0^{2n+1} 1^{2n} | n, m \geq 0\}$\
    $S \rightarrow 0X | 0$ \
    $X \rightarrow 0Y | 1Z$ \
    $Y \rightarrow 0X|0 $\
    $Z \rightarrow 1 | 1U$\
    $U \rightarrow 1Z$\
- [b] enthält mindestens zwei Nullen und höchstens eine Eins \

    $S \rightarrow 0X | 1A $\
    $X \rightarrow 0X|0|1Y|0Z$\
    $Y \rightarrow 0| 0Y$\
    $Z \rightarrow 1$\
    $A \rightarrow 0Y$\
- [c] enthält nicht das Teilwort 110
    $S \rightarrow 0|0S|1X|1$\
    $X \rightarrow 0|1|0S|1Y$\
    $Y \rightarrow 1| 1Y$\
- [d] siehe Aufgabenblatt
    $S \rightarrow 0X$\
    $X \rightarrow 1Y$\
    $Y \rightarrow 0Z$\
    $Z \rightarrow 1|1S$\

- [e] siehe Aufgabenblatt
    $S \rightarrow aX$\
    $X \rightarrow aY$\
    $Y \rightarrow bZ$\
    $Z \rightarrow b|bS$\
- [f] siehe Aufgabenblatt
    $S \rightarrow bX$\
    $X \rightarrow aY | bY$\
    $Y \rightarrow aX | bS$\
alternativ\
     $S \rightarrow bX$\
    $X \rightarrow aX | aY$\
    $Y \rightarrow b | bS$\
    
**Aufgabe 2**

**Typen: Chaomsky**

> ***Bemerkungen***: immer auf 2 und 3 zuerst nachchecken

1.  Typ 0 : keine Einschränkungen
2.  Typ 1 : *Kontextsensetiv* $\beta \in (\Sigma \cup N)^*$  und $\beta \geq 1$ \ 

> wenn a_1 auf der linken Seite vorhanden ist dann muss es auch auf der rechten sein und so weiter also Struktur einhalten und A wird zu $\beta$ beliebig\
    $a_1Aa_2 → a_1 \beta a_2$\
     Ausnahme \
    $S \rightarrow \epsilon$
     S kommt nicht auf der rechten Seite vor
.

3.  Typ 2: *kontextfrei* 
    A → β
    Ausnahme von Typ 1 gilt hier auch
4.  Typ 3: *regulär* $a \in \Sigma^*$ \
    A → aB \
    A → a \
     Ausnahme gilt\
     
- [a] von welchem Typ !\
Nicht von Typ 3 oder 2 regulär oder kontextfrei wegen der Grammatik 
0A → 000A\
Nicht vom Typ 1 wegen der Grammatik $S → ABA$ hier ist  $\beta = 0$\
Also vom Typ 0\

- [b] Umsetzung \
$S \rightarrow ABA \rightarrow 00A \rightarrow 0000A \rightarrow 00000$\

- [c] Beschreiben :\
$L(G) = \{0^{2n+1} | n \geq 1\} \cup \{\epsilon \}$\

- [d] Äqu. Grammatik\
    $S \rightarrow \epsilon | 0X$\
    $X \rightarrow 0Y$\
    $Y \rightarrow 0X | 0$\
    
    
**Aufgabe 3**

- [a] \
     $S \rightarrow aSbX | aSb | abX | ab$\
    $X \rightarrow bX | b$\
    
- [b] \
    $S \rightarrow X |Y$\
    $X \rightarrow aXb | ab$\
    $Y \rightarrow aYbb | abb$\

- [c] \
 $S \rightarrow aSc | aXc$\
    $X \rightarrow bXc |bc$\

- [d] \
     $S \rightarrow aaSb | aab | aaXb $\
    $X \rightarrow b | bX$\

- [e] \ 
> + heißt ohne leeres Wort, * mit leerem \
     $S \rightarrow XSY | XY $\
    $X \rightarrow a | b$\
$Y \rightarrow 0 | 1$\

**Aufgabe 4**

$L = \{0^n 1^n | n \geq 1\}$ ist eine *kotextfreie* aber nicht *regulär*\
$\{a(ab)^{2n} | n \geq 0\}$ ist *regulär* \
    $S \rightarrow a |aX$\
    $X \rightarrow bY $\
    $Y \rightarrow aZ $\
$Z \rightarrow bS $\


**Aufgabe 5**

$int \rightarrow +int2 | -int2|0|1|1 int3$\
$int2 \rightarrow 0 |1|1 int3$\
$int3 \rightarrow 0|1|0 int3| 1 int3$\


**Aufgabe 6 TEST**

> n,m stehen nicht in Bezieung das heißt *regulär* \ ; wenn n zweimal vorkommt dann *nicht regulär* wie $a^n b^{2n}$

1.  richtig, da \
     $S \rightarrow bX $\
    $X \rightarrow aX |aY$\
$Y \rightarrow bY | bZ$\
$Z \rightarrow a$\

2.  richtig
3.  richtig, ungerade Anzahl von $a_s$
4.  richtig
5.  falsch
6.  falsch
7.  richtig











</body> </html>
