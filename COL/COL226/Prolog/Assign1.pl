use_module(library(lists)).

/* Membership */
mem(X, []) :- fail.
mem(X, [X|_]) :- !.
mem(X, [_|R]) :- mem(X, R).

/* ----------------------------------------PART A----------------------------------------------- */


/* Reflexive_Transitive */
mem((X, X), rtc(R, S)) :- mem(X, S), !.
mem((X, Y), rtc(R, S)) :- mem((X, Y), R), !.
mem((X, Y), rtc(R, S)) :- mem((X, Z), R), mem((Z, Y), rtc(R, S)).

/* Ref_Trans_symm */
mem((X, X), rtsc(R, S)) :- mem(X, S), !.
mem((X, Y), rtsc(R, S)) :- mem((X, Y), R), !.
mem((X, Y), rtsc(R, S)) :- mem((X, Y), R), !.
mem((X, Y), rtsc(R, S)) :- mem((Y, X), R), !.
mem((X, Y), rtsc(R, S)) :- mem((X, Z), R), mem((Z, Y), rtsc(R, S)), !.
mem((X, Y), rtsc(R, S)) :- mem((Z, X), R), mem((Y, Z), rtsc(R, S)).

/* ---------------------------------------------Examples------------------------------------------ */

/*
mem((2, 3), rtsc([(1, 2), (1, 3)], [1, 2, 3])).
mem((3, 2), rtsc([(1, 2), (1, 3)], [1, 2, 3])).
mem((1, 1), rtsc([(1, 2), (1, 3)], [1, 2, 3])).
mem((2, 2), rtsc([(1, 2), (1, 3)], [1, 2, 3])).
mem((1, 4), rtsc([(1, 2), (2, 5), (4, 3), (3, 1)], [1, 2, 3, 4, 5])).
mem((2, 4), rtsc([(1, 2), (2, 5), (4, 3), (3, 1)], [1, 2, 3, 4, 5])).
mem((3, 4), rtsc([(1, 2), (2, 5), (4, 3), (3, 1)], [1, 2, 3, 4, 5])).
mem((2, 4), rtc([(1, 2), (2, 5), (4, 3), (3, 1), (2, 1), (5, 2), (3, 4), (1, 3)], [1, 2, 3, 4, 5])).
mem((2, 4), rtsc([(1, 2), (4, 3), (3, 1), (2, 1), (3, 4), (1, 3)], [1, 2, 3, 4, 5])).
mem((3, 5), rtsc([(1, 2), (2, 5), (4, 3), (3, 1)], [1, 2, 3, 4, 5])).
mem((3, 5), rtsc([(1, 2), (2, 5), (4, 3), (3, 1), (4, 6)], [1, 2, 3, 4, 5, 6])).
mem((4, 6), rtsc([(1, 2), (2, 5), (4, 3), (3, 1), (4, 6)], [1, 2, 3, 4, 5, 6])).
mem((6, 7), rtsc([(1, 2), (2, 5), (4, 3), (7, 1), (1, 6)], [1, 2, 3, 4, 5, 6, 7])).
*/


/* ----------------------------------------PART B----------------------------------------------- */

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

/* Assuming no duplicates in S1, S2
 here is an implementation of insert of S1, S2 */
insertI([], S2, []) :- !.
insertI([X|R], S2, [X|Z]) :- mem(X, S2), !, insertI(R, S2, Z).
insertI([X|R], S2, S3) :- insertI(R, S2, S3).

/* Assuming no duplicates in S1, S2
 here is an implementation of diff of S1, S2 */
diffI([], S2, []) :- !.
diffI(S1, [], S1) :- !.
diffI([X|R], S2, [X|Z]) :- \+ mem(X, S2), !, diffI(R, S2, Z).
diffI([X|R], S2, S3) :- diffI(R, S2, S3).

/* Assuming no duplicates in S1, S2
 here is an implementation of cartesian of S1, S2 */
cartesianH(_, [], []) :- !.
cartesianH(X, [Y|S], [[X|Y]|Z]) :- cartesianH(X, S, Z).

cartesianI([], _, []) :- !.
cartesianI(_, [], []) :- !.
cartesianI([X|R], S, Z) :- cartesianH(X, S, P), cartesianI(R, S, R1), append(P, R1, Z).

/* --------------------------------------------Examples----------------------------------------------------- */

/* ----------------------------- Union ----------------------------------
unionI([], [1, 2, 3, 4, 5], [1, 2, 3, 5, 4]). 
unionI([1, 2, 3, 4, 5], [], [1, 2, 3, 4, 5]). 
unionI([1, 17, 568], [34, 4, 3], [1, 568, 17, 34, 4, 3]). 
unionI([1, 17, 568], [34, 4, 3], [1, 17, 568, 34, 4, 3]). 
unionI([1, 17, 568], [34, 4, 568], R). 
unionI([], [], []).
unionI([], [[]], [[]]).
unionI([1, 17, 568], [34, 4, 17], R). -> to check for duplicates
unionI([3, 2], [2, 3], [3, 2]). -> to check for duplicates
unionI([2, 3], [3, 2], [2, 3]). -> to check for duplicates

------------------------------- Power -----------------------------------
powerI([1,2], [[], [1, 2], [1], [2]]). 
powerI([1,2], [[1, 2], [1], [2], []].). 
powerI([[]],  [[[]], []].). 
powerI([], [[]]).

------------------------------ InsertI ----------------------------------
insertI([], [1, 2, 3, 4, 5], []). 
insertI([1, 2, 3, 4, 5], [], []). 
insertI([1, 17, 568], [34, 4, 3], []). 
insertI([1, 17, 568], [34, 4, 568], [568]). 
insertI([], [], []).
insertI([], [[]], []).
insertI([], [[]], [[]]).
insertI([1, 17, 568], [34, 4, 17], R).
insertI([3, 2], [2, 3], [3, 2]). -> true
insertI([2, 3], [3, 2], [2, 3]). -> true
insertI([2, 3], [3, 2], R). -> [2, 3]

----------------------------- diffI ------------------------------------
diffI([], [1, 2, 3, 4, 5], R). -> R = [].
diffI([1, 2, 3, 4, 5], [], R). -> R = [1, 2, 3, 4, 5].
diffI([1, 17, 568], [34, 4, 3], R). -> R = [1, 17, 568].
diffI([1, 17, 568], [34, 4, 568], R). -> R = [1, 17].
diffI([], [], R). -> R = [].
diffI([], [[]], R). -> R = [].
diffI([[]], [], R). -> R = [[]].
diffI([1, 17, 568], [34, 4, 17], R). -> R = [1, 568].
diffI([3, 2], [2, 3], R). -> R = [].
diffI([2, 3], [3, 2], R). -> R = [].

---------------------------- caertesianI -----------------------------
cartesianI([], [1, 2, 3, 4, 5], R). -> R = []. 
cartesianI([1, 2, 3, 4, 5], [], R). -> R = []. 
cartesianI([1, 17], [34, 1], []). -> R = [[1|34], [1|1], [17|34], [17|1]].
cartesianI([1, 17, 568], [34, 4, 568], R). 
cartesianI([], [], R).
cartesianI([], [[]], R).
cartesianI([[]], [[]], R).
cartesianI([2, 3], [3, 2], R). -> R = [[2|3], [2|2], [3|3], [3|2]].

*/