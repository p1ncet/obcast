--TEST--
--SKIPIF--
<?php if(!extension_loaded('obcast')) echo 'skip'; ?>
--FILE--
<?php

var_dump(interface_exists('Boolable'));
var_dump(method_exists('Boolable', '__toBoolean'));

--EXPECT--
bool(true)
bool(true)