/* Membership */
mem(X, []) :- fail.
mem(X, [X|_]) :- !.
mem(X, [_|R]) :- mem(X, R).

/*  del(X,L1,L2) -- delete element X from a list L1 to obtain L2 */ 
del(X, [ ] , [ ]) :- !.
del(X, [X|R], Z) :- del(X, R, Z), !.
del(X, [Y|R], [Y|Z]) :- del(X, R, Z), !.

/*  remdups(L, L1) remove duplicates from a list L to get L1 */
remdups([ ], [ ]) :- !.
remdups([X|R], [X|Z]) :- del(X, R, L), remdups(L, Z).

/* Assuming no duplicates in S1, S2
 here is an implementation of union of S1, S2 */
unionI([ ], S2, S2) :- !.
unionI(S1, [ ], S1) :- !.
unionI([X|R], S2, [X|Z]) :- del(X, S2, S3),  unionI(R, S3, Z).

/* append(L1, L2, L3) -- append lis  L1 to list L2 to get list  L3 */
append( [ ], L, L).
append( [X|R], L, [X|Z]) :- append(R, L, Z).

/* mapcons(X,L1, L2) --  cons the element X to each list in L1 to get L2 */
mapcons(X, [ ], [ ]) :- !.
mapcons(X, [Y|R], [ [X|Y] | Z ]) :- mapcons(X, R, Z).

/* powerI( S, P1): Here is an implementation of powerset of S */
powerI([ ], [ [ ] ]) :- !.
powerI([X|R], P) :- powerI(R, P1),  mapcons(X, P1, P2), append(P2, P1, P).

/* interI(S1, S2, S3) */
interI([], S2, []) :- !.
interI([X|R], S2, [X|Z]) :- mem(X, S2), !, interI(R, S2, Z).
interI([X|R], S2, S3) :- interI(R, S2, S3).

/* diffI(S1, S2, S3) */
diffI([], S2, []) :- !.
diffI([X|R], S2, [X|Z]) :- \+ mem(X, S2), !, diffI(R, S2, Z).
diffI([X|R], S2, S3) :- diffI(R, S2, S3).

/* cartesian(S1, S2, S3) */
cartesianH(_, [], []) :- !.
cartesianH(X, [Y|S], [(X,Y)|Z]) :- cartesianH(X, S, Z).

cartesian([], _, []) :- !.
cartesian(_, [], []) :- !.
cartesian([X|R], S, Z) :- cartesianH(X, S, P), cartesian(R, S, R1), append(P, R1, Z).