<?php

    Class House {
        public function introduce() {
            print( "House " . $this->gethouseName() . " of "
                . $this->getHouseSeat() . " : \"" . $this->getHouseMotto()
                . "\"" . PHP_EOL );
        }
    }

?>