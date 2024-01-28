type(intT).
type(boolT).

hastype(_, intT(N), intT) :- integer(N), !.
hastype(_, boolT(B), boolT) :- member(B, [true, false]), !.
hastype(G, varT(X), T) :- member((X, T), G), !.

hastype(G, plus(E1, E2), intT) :- hastype(G, E1, intT), hastype(G, E2, intT), !.
hastype(G, subtract(E1, E2), intT) :- hastype(G, E1, intT), hastype(G, E2, intT), !.
hastype(G, divide(E1, E2), intT) :- hastype(G, E1, intT), hastype(G, E2, intT), !.
hastype(G, times(E1, E2), intT) :- hastype(G, E1, intT), hastype(G, E2, intT), !.

hastype(G, or(E1, E2), boolT) :- hastype(G, E1, boolT), hastype(G, E2, boolT), !.
hastype(G, and(E1, E2), boolT) :- hastype(G, E1, boolT), hastype(G, E2, boolT), !.
hastype(G, implies(E1, E2), boolT) :- hastype(G, E1, boolT), hastype(G, E2, boolT), !.
hastype(G, not(E1), boolT) :- hastype(G, E1, boolT), !.
hastype(G, xor(E1), boolT) :- hastype(G, E1, boolT), !.

hastype(G, eq(E1, E2), boolT) :- hastype(G, E1, intT), hastype(G, E2, intT), !.
hastype(G, gt(E1, E2), boolT) :- hastype(G, E1, intT), hastype(G, E2, intT), !.
hastype(G, gte(E1, E2), boolT) :- hastype(G, E1, intT), hastype(G, E2, intT), !.