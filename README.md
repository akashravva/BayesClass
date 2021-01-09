# BayesClass
The project determines the class from the given data using Naive Bayes classification.

Processor determines the class from the sample data provided.
Processor executes upon the timer expiry which is configured to 10ms.
As soon as the ISR is executed, the processor is put back into the low power mode.

Used HSE CLK 8 Mhz, Prescalar 8000, driving the clock to 1khz, Counter period is 10 giving 10ms Timer configuration.
TIMx_EGR reinitializes the timer counter and genrates an update of the registers. Sub routing is triggered upon the callback.



