--TEST--
Check sort int
--FILE--
<?php
$a = array("a","b","c","d","e");
mysort($a);
print_r($a);
$b = array("e","d","c","b","a");
mysort($b);
print_r($b);
--EXPECT--
Array
(
    [0] => a
    [1] => b
    [2] => c
    [3] => d
    [4] => e
)
Array
(
    [0] => a
    [1] => b
    [2] => c
    [3] => d
    [4] => e
)

