<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <?php
    echo "ayo <br>";
    $length = "John<br>";
    echo $length;


    $matrix = array(1, "John", 4);
    echo $matrix[1];
    echo "<br>";

    $string = "This is a list to be created";
    $listsWithSpaces = explode(" ", $string);

    echo $listsWithSpaces[2];

    # now writing actual block of code
    $input = "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
    Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
    Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
    Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
    Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green";
    $lines = explode("\n", $input);

    foreach ($lines as $line) {
        echo $line;
        echo "<br>";
    }
    ?>
</body>

</html>