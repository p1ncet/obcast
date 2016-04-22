--TEST--
--SKIPIF--
<?php if(!extension_loaded('obcast')) echo 'skip'; ?>
--FILE--
<?php

class FalseClass implements Boolable {
	public function __toBoolean() {
		return false;
	}
}

$b = new FalseClass();

var_dump($b instanceof Boolable);

var_dump($b->__toBoolean());
var_dump((bool) $b);
var_dump(boolval($b));
if ($b) {
	var_dump(true);
} else {
	var_dump(false);
}
var_dump($b ? true : false);
--EXPECT--
bool(true)
bool(false)
bool(false)
bool(false)
bool(false)
bool(false)