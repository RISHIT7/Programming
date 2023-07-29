-- Calling the entity somewhat like in java, for input and output
ENTITY T01_HelloWorld_tb IS
END ENTITY;

-- Building the architecture, for most computation that is the algorithms
ARCHITECTURE sim OF T01_HelloWorld_tb IS
BEGIN

    PROCESS IS
    BEGIN

        REPORT "Hello World!";
        WAIT;

    END PROCESS;

END ARCHITECTURE;