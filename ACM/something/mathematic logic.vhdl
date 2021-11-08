library ieee;
use ieee.std_logic_1164.all;

entity tte is
    port (
        A : in std_logic_vector (2 downto 0);
        B : out std_logic_vector (7 downto 0));
end tte;

architecture TTE of tte is
begin:
    process (A)
        if A = "000" then b <= "00000001";
        elsif A = "001" then b <= "00000010";
        elsif A = "010" then b <= "00000100";
        elsif A = "011" then b <= "00001000";
        elsif A = "100" then b <= "00010000";
        elsif A = "101" then b <= "00100000";
        elsif A = "110" then b <= "01000000";
        elsif A = "111" then b <= "10000000";
        end if;
    end process;
end TTE;