--TEST--
Check swap object
--FILE--
<?php
class Party {
    protected $name;
    public function __construct($name) {
        $this->name = $name;
    }
    public function getName() {
        return $this->name;
    }
}

$in = new Party("KMT");
$out = new Party("DDP");
swap($in, $out);
echo $in->getName();
echo $out->getName();
--EXPECT--
DDPKMT
