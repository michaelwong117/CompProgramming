def Temperature(Fahrenheit):
    '''(number) -> floats

    Return the number of Celsius degrees equivalent to Fahrenheit degrees.

    >>> Temperature(32)
    0.0
    >>> Temperature(212)
    100.0
    '''

    return (Fahrenheit - 32) * 5 / 9
