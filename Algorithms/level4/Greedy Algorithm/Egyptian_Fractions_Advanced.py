import math
import fractions
import functools

def validate(function):
    @functools.wraps(function)
    def wrapper(fraction):
        total = fractions.Fraction(0)
        for egyptian in function(fraction):
            if 1 not in {egyptian.numerator, egyptian.denominator}:
                raise AssertionError('function has failed validation')
            yield egyptian
            total += egyptian
        if total != fraction:
            raise AssertionError('function has failed validation')
    return wrapper


@validate
def to_egyptian_fractions(fraction):
    quotient = math.floor(fraction.numerator / fraction.denominator)
    if quotient:
        egyptian = fractions.Fraction(quotient, 1)
        yield egyptian
        fraction -= egyptian
    while fraction:
        quotient = math.ceil(fraction.denominator / fraction.numerator)
        egyptian = fractions.Fraction(1, quotient)
        yield egyptian
        fraction -= egyptian

def main():
    f = fractions.Fraction(3, 4)
    e = to_egyptian_fractions(f)
    print(*e, sep=' + ')
    f = fractions.Fraction(6, 7)
    e = to_egyptian_fractions(f)
    print(*e, sep=' + ')
    f = fractions.Fraction(7654, 321)
    e = to_egyptian_fractions(f)
    print(*e, sep=' + ')

if __name__ == '__main__':
    main()