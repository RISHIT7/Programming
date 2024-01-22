from myhdl import block, always_seq

@block
def Booths_Multiplication(a, b, clk, c, clock_cycle):

    multiplicand = a
    multiplier = b
    counter = 0
    bin_literal = int("0000000000000000", 2)
    result = [0] * 32
    s = 0
    clock_num = 0

    @always_seq(clk.posedge, reset=None)
    def multiplication_process():
        nonlocal multiplicand, multiplier, counter, bin_literal, result, s, clock_num

        if counter < 17:
            if counter == 0:
                result[:16] = multiplicand
                result[16:] = bin_literal
                s = 0
                counter += 1
            elif result[0] == 0 and s == 1:
                result[16:] = [x + y for x, y in zip(result[16:], multiplier)]
                s = result[0]
                result[1:] = result[:-1]
                counter += 1
            elif result[0] == 1 and s == 0:
                result[16:] = [x + 1 for x in [(not x) for x in multiplier]]  # NOT b + 1
                s = result[0]
                result[1:] = result[:-1]
                counter += 1
            else:
                counter_var = counter
                while result[0] == s:
                    s = result[0]
                    result[1:] = result[:-1]
                    counter_var += 1
                counter = counter_var

                clock_num += 1

        c.next = tuple(result)

    clock_cycle.next = clock_num

    return multiplication_process

# Example usage:
from myhdl import Simulation, traceSignals, intbv, delay, always, instance, StopSimulation

def test_bench():
    a = intbv(0)[16:]
    b = intbv(0)[16:]
    clk = bool(0)
    c = intbv(0)[32:]
    clock_cycle = intbv(0)[32:]

    dut = Booths_Multiplication(a, b, clk, c, clock_cycle)

    @always(delay(10))
    def clock_gen():
        clk.next = not clk

    @block
    def stimulus():
        @instance
        def stimulus_inst():
            a.next = intbv(273)[16:]
            b.next = intbv(167)[16:]
            yield delay(10)

            a.next = intbv(123)[16:]
            b.next = intbv(456)[16:]
            yield delay(10)

            # Add more test cases as needed

            raise StopSimulation

        return stimulus_inst

    sim = Simulation(traceSignals(dut), clock_gen(), stimulus())
    sim.run()

test_bench()
