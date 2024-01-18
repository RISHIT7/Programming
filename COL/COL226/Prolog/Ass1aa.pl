use_module(library(lists)).

/* Membership */
mem(X, []) :- fail.
mem(X, [X|_]) :- !.
mem(X, [_|R]) :- mem(X, R).


/* Symm_helper */
symm_h([], S, Z). 
symm_h([(X, X)|R], S, S) :- symm_h(R, S, S), !.
symm_h([(X, Y)|R], S, [(Y, X)|S]) :- symm_h(R, S, S).
symm(R, S) :- symm_h(R, R, S).

/* Reflexive_Transitive */
mem((X, X), rc(R, S)) :- mem(X, S), !.
mem((X, Y), rc(R, S)) :- mem((X, Y), R), !.
/* R^0 */

/* tc(X, Y, _, R) :- mem((X, Y), R), !. */
/* tc(X, Y, Visited, R) :- mem((X, Z), R), \+ mem(Z, Visited), tc(Z, Y, [Z | Visited], R). */
/* mem((X, Y), tc(R, S)) :- tc(X, Y, [], R). */

tc(X, Y, _, R) :- mem((X, Y), R), !.
tc(X, Y, Visited, R) :- mem((X, Z), R), \+ member(Z, Visited), tc(Z, Y, [Z | Visited], R).

/* UR^i */

mem((X, X), rtc(R, S)) :- mem(X, S), !.
mem((X, Y), rtc(R, S)) :- mem((X, Y), tc(R, S)).

/* Ref_Trans_Symm */
mem((X, Y), sc(R, S)) :- mem((X, Y), R), !.
mem((Y, X), sc(R, S)) :- mem((X, Y), R), !.

mem((X, X), rtsc(R, S)) :- mem(X, S), !.

mem((X, Y), rtsc(R, S)) :- mem((X, Y), R).
mem((X, Y), rtsc(R, S)) :- mem((Y, X), R).

mem((X, Y), rtsc(R, S)) :- tc(X, Y, [], Z), Z is symm(R, Z).
