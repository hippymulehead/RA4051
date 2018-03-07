#define RA4051_h
#ifdef RA4051_h

/*
Simple object for controlling a 4051 multiplexer.  This just does the writes
and keeps track of the pin that's set on the 4051.
*/

class RA4051 {
    public:
        // Init the object and set the pins to use for s0-s2
        RA4051(int s0, int s1, int s2);
        // Use this init if to demux
        RA4051(int s0, int s1, int s2, int readPin);
        // Set the multiplexer pin to "pinToSet"
        void setPin(int pinToSet);
        // Get what pin is currently set
        int getCurrentPin();
        // Enable the 4051
        void on();
        // Disable the 4051
        void off();
        // Turn set the pin to use for enable
        void setEnablePin(int enablePin);
        // Digital demux read
        int RADigitalRead();
        // Analog demux read
        int RAAnalogRead();
    protected:
        int             m_s0;
        int             m_s1;
        int             m_s2;
        int             m_e;
        int             m_enableBit;
        int             m_eb;
        int             m_currentPin;
        int             m_readPin;
        int             m_cr;
    private:
};
#endif
