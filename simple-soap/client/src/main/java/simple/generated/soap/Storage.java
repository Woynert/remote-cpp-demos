
package simple.generated.soap;

import java.util.ArrayList;
import java.util.List;
import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;

/**
 * <p>Java class for storage complex type.
 *
 * <p>The following schema fragment specifies the expected content contained within this class.
 *
 * <pre>
 * &lt;complexType name="storage">
 *   &lt;complexContent>
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType">
 *       &lt;sequence>
 *         &lt;element name="title" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/>
 *         &lt;element name="songs" type="{http://soap.server.simple/}song" maxOccurs="unbounded"
 * minOccurs="0"/> &lt;/sequence> &lt;/restriction> &lt;/complexContent> &lt;/complexType>
 * </pre>
 *
 *
 */
@XmlAccessorType (XmlAccessType.FIELD)
@XmlType (name = "storage", propOrder = { "title", "songs" })
public class Storage
{

	protected String title;
	@XmlElement (nillable = true) protected List<Song> songs;

	/**
	 * Gets the value of the title property.
	 *
	 * @return
	 *     possible object is
	 *     {@link String }
	 *
	 */
	public String getTitle () { return title; }

	/**
	 * Sets the value of the title property.
	 *
	 * @param value
	 *     allowed object is
	 *     {@link String }
	 *
	 */
	public void setTitle (String value) { this.title = value; }

	/**
	 * Gets the value of the songs property.
	 *
	 * <p>
	 * This accessor method returns a reference to the live list,
	 * not a snapshot. Therefore any modification you make to the
	 * returned list will be present inside the JAXB object.
	 * This is why there is not a <CODE>set</CODE> method for the songs property.
	 *
	 * <p>
	 * For example, to add a new item, do as follows:
	 * <pre>
	 *    getSongs().add(newItem);
	 * </pre>
	 *
	 *
	 * <p>
	 * Objects of the following type(s) are allowed in the list
	 * {@link Song }
	 *
	 *
	 */
	public List<Song> getSongs ()
	{
		if (songs == null) {
			songs = new ArrayList<Song> ();
		}
		return this.songs;
	}
}
