--TEST--
Check sort int
--FILE--
<?php
$a = array(1,2,3,4,5);
mysort($a);
print_r($a);
$b = array(5,4,3,2,1);
mysort($b);
print_r($b);
--EXPECT--
Array
(
    [0] => 1
    [1] => 2
    [2] => 3
    [3] => 4
    [4] => 5
)
Array
(
    [0] => 1
    [1] => 2
    [2] => 3
    [3] => 4
    [4] => 5
)

