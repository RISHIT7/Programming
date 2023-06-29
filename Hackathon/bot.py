# "LINK = https://discord.com/api/oauth2/authorize?client_id=1064530739149946900&permissions=1634235578432&scope=bot "

import numpy as np
import discord
import copy
TOKEN = "MTA2MzkwMTE4MjU1ODQ3MDIwNA.G1cD1W.keDYitYU1_2-RlC4lz0Xa7axxCiRoaS43Bw8gg"


intents = discord.Intents.default()
intents.message_content = True
client = discord.Client(intents=intents)


@client.event
async def on_ready():
    print('We have logged in as {0.user}'.format(client))


@client.event
async def on_message(message):

    #-----------------GREETINGS-----------------#

    if message.content.lower() == "hi":
        await message.channel.send(f"Hiii {message.author}, type !help for details on how to use the bot.")

    if message.content.lower() == "hey":
        await message.channel.send(f"Hey there {message.author}, type !help for details on how to use the bot.")

    if message.content.lower() == "hello":
        await message.channel.send(f'Hello {message.author}, type !help for details on how to use the bot.')

    sum = 0

#-----------------ALGEBRA-----------------#

#-----------------ADDITION-----------------#

    # checking operator
    if message.content[0] == '+':
        Fnums = message.content.split()
        Fnums.remove('+')

        for i, e in enumerate(Fnums):
            if '/' in e:
                [a, b] = e.split('/')
                c = float(a)/float(b)
                Fnums[i] = c
            else:
                Fnums[i] = float(e)  # converting the string to float
        nums = copy.deepcopy(Fnums)

        # calculating number of decimal digits

        i = 0
        Dec_f = 0
        while i < len(nums):
            dec = 0
            while (nums[i]*10) % 10 != 0:
                dec += 1
                nums[i] *= 10
                print(nums[i])
            Dec_f = max(Dec_f, dec)
            i += 1

        # calculating sum
        for el in Fnums:
            sum += el*(10**Dec_f)

        # rounding off
        if (sum*10) % 10 >= 5:
            sum = np.ceil(sum)
        elif (sum*10) % 10 < 5:
            sum = np.floor(sum)

        # printing the answer
        if len(nums) == 1:
            await message.channel.send(f"The value of the fraction is {str(sum/(10**Dec_f))}")

        else:
            await message.channel.send(f"The sum of the numbers are {str(sum/(10**Dec_f))}")

    prod = 1

#-----------------MULTIPLICATION-----------------#

    # checking operator
    if message.content[0] == '*':
        nums = message.content.split()
        nums.remove()
        for i, e in enumerate(nums):
            if '/' in e:
                [a, b] = e.split('/')
                c = float(a)/float(b)
                nums[i] = c

        # converting the values to float
        for elements in nums:
            prod *= float(elements)

        # printing the answer
        if len(nums) == 1:
            await message.channel.send(f"The value of the fraction is {str(prod)}")

        else:
            await message.channel.send(f"The product of the numbers is {str(prod)}")

#-----------------ROOTS-----------------#

    # checking the operator
    if "roots" in message.content.lower():

        # collecting the input
        coeff = message.content.split()
        coeff.remove("roots")

        # logging th e coefficients
        print(f"Coefficients are : {coeff}")
        coeff = [float(i) for i in coeff]
        r = np.roots(coeff)

        # printing the answer
        await message.channel.send(f"The roots of the polynomial with the given coefficients {coeff} are {r}")

#-----------------DIFFERENTIATION-----------------#

    # checking the operator
    if "diff" in message.content.lower():

        # collecting the input
        coeff = message.content.split()
        coeff.remove("diff")

        # logging the coefficients
        print(f"Coefficients are : {coeff}")
        coeff = [float(i) for i in coeff]

        # creating result list
        res = []
        i = 0
        while i < len(coeff) - 1:
            res.append(coeff[i]*(len(coeff)-i-1))
            i += 1

        # printing the answer
        await message.channel.send(f"The derivateive of the function has degree {len(res)-1} and coefficients {res}")

#-----------------HELP-----------------#

    if message.content.lower() == "!help":
        await message.channel.send("""OPTIMUS_MEGABYTE can help you in the following ways: \n
1) The Plus function!, all you need to do is type '+ numbers' for example '+ 5 2 3 6 4' and voila the sum or subtraction is right there in front of you. \n
2) The Product function!!, example '* 5 6 2 5 4' and as easy as that you can compute multiplication or division of as many numbers as you want !!! \n
3) To find the roots of any Polynomial function, all you need to do is type 'roots a b c d' where a, b, c, d are the coefficients of the polynomial function of degree 4 in this case. #DO NOT FORGET THE ZEROS IN COEFFICIENTS!!! \n
4) Differentiation of a Polynomial function !!, example:- 'diff n a b c' where n is the degree and a, b, c are the coefficients. #DO NOT FORGET THE ZEROS IN THE COEFFICIENTS!!! \n
5) To find the value of a fraction simply use  the '+' or the '*' operator to get it's value. \n---> '+ 1/5' gives output as 2.0 \n ---> '* 1/9' gives output as 0.1111111111111111""")


client.run(TOKEN)

