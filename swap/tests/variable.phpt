--TEST--
Check swap variable
--FILE--
<?php
$a = 1;
$b = 2;
swap($a, $b);
echo $a;
echo $b;
--EXPECT--
21
