use_module(library(lists)).

mem(X, []) :- fail.
mem(X, [X|R]) :- !.
mem(X, [_|R]) :- mem(X, R).