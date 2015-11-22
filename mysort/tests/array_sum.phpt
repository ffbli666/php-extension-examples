--TEST--
Check sort int
--FILE--
<?php
$a = array(1,2,3,4,5);
echo myarray_sum($a);
echo "\n";
$b = array("a","b","c","d","e");
echo myarray_sum($b);
--EXPECT--
15
0