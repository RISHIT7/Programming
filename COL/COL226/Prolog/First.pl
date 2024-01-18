% Symmetric closure
symm([], []).
symm([(X, Y)|R], [(X, Y), (Y, X)|S]) :- symm(R, S).

% Transitive closure
tc(X, Y, _) :- connected(X, Y), !.
tc(X, Y, Visited) :- connected(X, Z), \+ member(Z, Visited), tc(Z, Y, [Z | Visited]).

% Union
union([], L, L).
union([H|T], L, Result) :- member(H, L), !, union(T, L, Result).
union([H|T], L, [H|Result]) :- union(T, L, Result).

% U(R^i U R^-i)
ur_closure(X, Y, R) :- tc(X, Y, []), !.
ur_closure(X, Y, R) :- symm(R, SymmetricR), tc(X, Y, [], SymmetricR).

% Example usage
connected(a, b).
connected(b, c).
\+ connected(c, d).
connected(d, e).
