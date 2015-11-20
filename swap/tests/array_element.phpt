--TEST--
Check swap array
--FILE--
<?php
$a = array(1,2,3);
$b = array('a','b','c');
swap($a[1],$b[1]);
print_r($a);
print_r($b);
--EXPECT--
Array
(
    [0] => 1
    [1] => b
    [2] => 3
)
Array
(
    [0] => a
    [1] => 2
    [2] => c
)
