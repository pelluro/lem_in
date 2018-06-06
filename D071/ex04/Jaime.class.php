<?php

    Class Jaime extends Lannister {
        private $gross = "With pleasure, but only in a tower in Winterfell, then.";

        public function sleepWith($who) {
            if ($who instanceof Cersei) {
                print $this->gross . PHP_EOL;
                return;
            }
            parent::sleepWith($who);
        }
    }

?>