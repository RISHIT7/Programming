% subset/2 checks if the first argument is a subset of the second argument
subset([], _).
subset([X|Xs], Set) :-
    member(X, Set),
    subset(Xs, Set).

% set_equal/2 checks if two sets are equal
set_equal(Set1, Set2) :-
    subset(Set1, Set2),
    subset(Set2, Set1),
    length(Set1, Length),
    length(Set2, Length), !.

set_of_sets_equal(Sets1, Sets2) :-
    length(Sets1, Length),
    length(Sets2, Length),
    forall(member(Set1, Sets1), (
        member(Set2, Sets2),
        set_equal(Set1, Set2)
    )),
    forall(member(Set2, Sets2), (
        member(Set1, Sets1),
        set_equal(Set1, Set2)
    )).

/*set_of_sets_equal([[1, 2, 3], [1, 2], [1, 3], [1], [2, 3], [2], [3], []],
 [[2, 1, 3], [2, 1], [2, 3], [2], [1, 3], [1], [3], []]).*/