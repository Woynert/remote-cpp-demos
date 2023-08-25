package capyfile.rmi;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class MessageTest
{
	@Test void someCreationTest ()
	{
		Message msg = new Message ("Hello there");

		assertTrue (msg.content == "Hello there", "Content should be set");
	}
}
