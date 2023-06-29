# works for non-complex fractions with value less than 1
import math

def eqyptian_frac(numerator, denominator):
    # Creating list of denominators of egyptian fraction
    egypt_list = []
    while numerator != 0:
        x = math.ceil(denominator/numerator)
        egypt_list.append(x)

        numerator = x * numerator - denominator
        denominator *= x

    str = ""
    for ones in egypt_list:
        str += "1/{0} + ".format(ones)
    final_string = str[:-3]
    return final_string

print(eqyptian_frac(7, 12))