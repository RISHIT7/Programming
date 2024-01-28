type(intT).
type(boolT).

hastype(_, intT(N), intT) :- integer(N), !.
hastype(_, boolT(B), boolT) :- member(B, [true, false]), !.