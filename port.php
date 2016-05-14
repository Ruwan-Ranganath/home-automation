<?php 

$output = shell_exec('dmesg | grep ttyACM');
echo "<pre>$output</pre>";
echo "use your port as /dev/ttyACM{id} ";
?>
