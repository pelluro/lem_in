<?php

    Class NightsWatch {

        private $figther = array ();

        public function recruit($who) {
            $this->fighter[] = $who;
        }

        public function fight() {
            foreach ($this->fighter as $soldier) {
                if ($soldier instanceof Ifighter)
                    $soldier->fight();
            }
        }
    }

?>