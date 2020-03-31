LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY registre_8b IS
  PORT( clk, rst, wr : IN STD_LOGIC;
          dataIn : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
          dataOut : OUT STD_LOGIC_VECTOR(7 DOWNTO 0));
END ENTITY registre_8b;

ARCHITECTURE comp OF registre_8b IS
  BEGIN
    PROCESS (clk)
      BEGIN
        IF RISING_EDGE(clk)THEN
          IF (rst = '1') THEN
            dataOut <= "00000000";
          ELSIF (wr = '1')THEN
            dataOut <= dataIn;
          END IF;
        END IF;
    END PROCESS;
END ARCHITECTURE comp;
