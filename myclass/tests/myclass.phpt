--TEST--
Check myclass
--FILE--
<?php
$in = new MyClass("KMT");
echo $in->getName() . "\n";
$in->setName("DPP");
echo $in->getName() . "\n";
echo $in->helloWorld() . "\n";
--EXPECT--
KMT
DPP
Hello World