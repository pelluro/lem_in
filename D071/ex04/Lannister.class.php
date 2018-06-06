<?php

    Class Lannister {
        private $yeah = "Let's do this.";
        private $noway = "Not even if I'm drunk !";

        public function sleepWith($who) {
            if ($who instanceof Lannister)
                print $this->noway . PHP_EOL;
            else
                print $this->yeah . PHP_EOL;
        }
    }

?>