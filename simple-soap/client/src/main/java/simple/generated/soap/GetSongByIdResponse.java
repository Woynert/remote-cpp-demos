
package simple.generated.soap;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;

/**
 * <p>Java class for getSongByIdResponse complex type.
 *
 * <p>The following schema fragment specifies the expected content contained within this class.
 *
 * <pre>
 * &lt;complexType name="getSongByIdResponse">
 *   &lt;complexContent>
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType">
 *       &lt;sequence>
 *         &lt;element name="return" type="{http://soap.server.simple/}song" minOccurs="0"/>
 *       &lt;/sequence>
 *     &lt;/restriction>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 *
 *
 */
@XmlAccessorType (XmlAccessType.FIELD)
@XmlType (name = "getSongByIdResponse", propOrder = { "_return" })
public class GetSongByIdResponse
{

	@XmlElement (name = "return") protected Song _return;

	/**
	 * Gets the value of the return property.
	 *
	 * @return
	 *     possible object is
	 *     {@link Song }
	 *
	 */
	public Song getReturn () { return _return; }

	/**
	 * Sets the value of the return property.
	 *
	 * @param value
	 *     allowed object is
	 *     {@link Song }
	 *
	 */
	public void setReturn (Song value) { this._return = value; }
}
