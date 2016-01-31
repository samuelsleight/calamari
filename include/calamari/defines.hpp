//
// Created by Sam Sleight on 18/01/2016.
//

#ifndef CALAMARI_DEFINES_HPP
#define CALAMARI_DEFINES_HPP

#define CALAMARI_NS_NAME calamari
#define CALAMARI_NS namespace CALAMARI_NS_NAME {
#define CALAMARI_NS_END }

#define CALAMARI_GLSL(name, source) const GLchar* name = "#version 330\n" #source

#define CALAMARI_KEY_X(expander) \
    expander(Escape, ESCAPE) \
    expander(Space,  SPACE) \
\
    expander(Up,    UP) \
    expander(Down,  DOWN) \
    expander(Left,  LEFT) \
    expander(Right, RIGHT) \
\
    expander(A,  A) \
    expander(B,  B) \
    expander(C,  C) \
    expander(D,  D) \
    expander(E,  E) \
    expander(F,  F) \
    expander(G,  G) \
    expander(H,  H) \
    expander(I,  I) \
    expander(J,  J) \
    expander(K,  K) \
    expander(L,  L) \
    expander(M,  M) \
    expander(N,  N) \
    expander(O,  O) \
    expander(P,  P) \
    expander(Q,  Q) \
    expander(R,  R) \
    expander(S,  S) \
    expander(T,  T) \
    expander(U,  U) \
    expander(V,  V) \
    expander(W,  W) \
    expander(X,  X) \
    expander(Y,  Y) \
    expander(Z,  Z) \
\
    expander(Zero,  0) \
    expander(One,   1) \
    expander(Two,   2) \
    expander(Three, 3) \
    expander(Four,  4) \
    expander(Five,  5) \
    expander(Six,   6) \
    expander(Seven, 7) \
    expander(Eight, 8) \
    expander(Nine,  9) \
\
    expander(Other, UNKNOWN)

#endif //CALAMARI_DEFINES_HPP
