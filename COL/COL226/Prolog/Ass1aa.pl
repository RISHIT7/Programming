use_module(library(lists)).

/* Membership */
mem(X, []) :- fail.
mem(X, [X|_]) :- !.
mem(X, [_|R]) :- mem(X, R).

/* Reflexive_Transitive */
mem((X, X), rc(R, S)) :- mem(X, S), !.
mem((X, Y), rc(R, S)) :- mem((X, Y), R), !.
/* R^0 */

mem((X, Y), tc(R, S)) :- mem((X, Y), R), !.
mem((X, Z), tc(R, S)) :- mem((X, Y), R), mem((Y, Z), tc(R, S)).
/* UR^i */

mem((X, X), rtc(R, S)) :- mem(X, S), !.
mem((X, Y), rtc(R, S)) :- mem((X, Y), R), !.
mem((X, Z), rtc(R, S)) :- mem((X, Y), R), mem((Y, Z), rtc(R, S)).

/* Ref_Trans_Symm */
mem((X, Y), sc(R, S)) :- mem((X, Y), R), !.
mem((Y, X), sc(R, S)) :- mem((X, Y), R), !.

mem((X, X), rtsc(R, S)) :- mem(X, S), !.
mem((X, Y), rtsc(R, S)) :- mem((X, Y), R), !.
mem((X, Y), rtsc(R, S)) :- mem((Y, X), R), !.
mem((X, Z), rtsc(R, S)) :- mem((X, Y), R), mem((Y, Z), rtsc(R, S)).
mem((X, Z), rtsc(R, S)) :- mem((Y, X), R), mem((Z, Y), rtsc(R, S)), \+ mem((Y, Z), rtsc(R, S)).
